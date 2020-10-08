#include "node.h"
using namespace std;

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &new_command, const shared_ptr<Node> left,
                                           const shared_ptr<Node> right): command(new_command),_left(left),_right(right){}
EventComparisonNode::EventComparisonNode(const Comparison &new_cmp, const string &new_event): cmp(new_cmp),event(new_event) {}
DateComparisonNode::DateComparisonNode(const Comparison &new_cmp, const Date &new_date): cmp(new_cmp),date(new_date) {}
bool EmptyNode::Evaluate(const Date& _date,const string& _event) const{
    return true;
}
bool LogicalOperationNode::Evaluate(const Date &_date, const string& _event) const {
    if (command==LogicalOperation::And) return _left->Evaluate(_date,_event) && _right->Evaluate(_date,_event);
    else return _left->Evaluate(_date,_event) || _right->Evaluate(_date,_event);
}
bool EventComparisonNode::Evaluate(const Date& _date, const string& _event) const {
    switch (cmp){
        case Comparison::Equal :
            return event == _event;
            break;
        case Comparison::NotEqual :
            return event != _event;
            break;
        case Comparison::Greater :
            return event < _event;
            break;
        case Comparison::GreaterOrEqual :
            return event <=_event;
            break;
        case Comparison::Less :
            return event > _event;
            break;
        case Comparison::LessOrEqual :
            return event >= _event;
            break;
    }
}
bool DateComparisonNode::Evaluate(const Date& _date, const string& _event) const {
    switch (cmp){
        case Comparison::Equal :
            return date.GetYear()*365+date.GetMonth()*30+date.GetDay() ==
                          _date.GetYear()*365+_date.GetMonth()*30+_date.GetDay();
            break;
        case Comparison::NotEqual :
            return date.GetYear()*365+date.GetMonth()*30+date.GetDay() !=
                   _date.GetYear()*365+_date.GetMonth()*30+_date.GetDay();
            break;
        case Comparison::Greater :
            return date.GetYear()*365+date.GetMonth()*30+date.GetDay() <
                   _date.GetYear()*365+_date.GetMonth()*30+_date.GetDay();
            break;
        case Comparison::GreaterOrEqual :
            return date.GetYear()*365+date.GetMonth()*30+date.GetDay() <=
                   _date.GetYear()*365+_date.GetMonth()*30+_date.GetDay();
            break;
        case Comparison::Less :
            return date.GetYear()*365+date.GetMonth()*30+date.GetDay() >
                   _date.GetYear()*365+_date.GetMonth()*30+_date.GetDay();
            break;
        case Comparison::LessOrEqual :
            return date.GetYear()*365+date.GetMonth()*30+date.GetDay() >=
                   _date.GetYear()*365+_date.GetMonth()*30+_date.GetDay();
            break;
    }
}