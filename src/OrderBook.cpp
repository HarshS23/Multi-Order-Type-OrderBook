#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>



enum class OrderType{
    GoodTillCancel, 
    FillandSell
};

enum class Side{
    Buy, 
    Sell
};

using Price = std::int32_t; 
using Quanitity = std::uint32_t;
using OrderId = std::uint64_t;

struct LevelInfo{
    Price price_;
    Quanitity quantity_;

};

using LevelInfos = std::vector<LevelInfo>;

class OrderbookLevelInfos{
    public:
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
    : bids_{bids} 
    , asks_{asks} 
    {};

    private:
    LevelInfos bids_;
    LevelInfos asks_;

};



class Order{
    public:
    Order(OrderType orderType, OrderId orderId, Side side , Price price, Quanitity quanitity)
    : orderType_{orderType}
    , orderId_{orderId}
    , side_{side}
    , price_{price}
    , initialQuantity_{quanitity}
    , remainingQuantity_{quanitity}
    {};

    OrderId GetOrderId() const {return orderId_;} 
    Side GetSide() const {return side_;}
    Price GetPrice() const {return price_;}
    OrderType GetOrderType() const {return orderType_;}
    Quanitity GetInitialQuantity() const {return initialQuantity_;}
    Quanitity GetRemainingQuantity() const {return remainingQuantity_;}
    Quanitity GetFilledQuantity() const {return GetInitialQuantity() - GetRemainingQuantity();}

    // when a trade happens, the lowest quantity between both orders is used to fill both orders 
    void Fill(Quanitity quantity){
        if(quantity > GetRemainingQuantity()){
            throw std::logic_error(std::format("Order({}) cannot be filled for more than its remaining quantity.", GetOrderId()));
        }

        remainingQuantity_ -= quantity;
    }


    private:
    OrderType orderType_;
    OrderId orderId_; 
    Side side_;
    Price price_;
    Quanitity quanitity_;
    Quanitity initialQuantity_;
    Quanitity remainingQuantity_;

};


using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;







int main(){
    return 0;
}