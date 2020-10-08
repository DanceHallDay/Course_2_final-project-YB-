#pragma once
#include "date.h"
#include "token.h"
#include <memory>
using namespace std;
enum class LogicalOperation{
    Or,
    And
};
class Node{
public:
    virtual bool Evaluate(const Date& _date, const string& _event) const = 0;
};
class EmptyNode:public Node{
public:
  bool Evaluate(const Date& _date, const string& _event) const override;
};
class DateComparisonNode : public Node{
public:
  DateComparisonNode(const Comparison& new_cmp,const Date& new_date);
  bool Evaluate(const Date& _date,const string& event) const override;
private:
  const Date date;
  const Comparison cmp;
};
class EventComparisonNode: public Node{
public:
  EventComparisonNode(const Comparison& new_cmp,const string& new_event);
  bool Evaluate(const Date& _date, const string& _event) const override;
private:
  const string event;
  const Comparison cmp;
};
class LogicalOperationNode : public Node{
public:
  LogicalOperationNode(const LogicalOperation& new_command,const shared_ptr<Node> left, const shared_ptr<Node> right);
  bool Evaluate(const Date& _date, const string& _event) const override;
private:
  const LogicalOperation command;
  shared_ptr<const Node> _left,_right;
};