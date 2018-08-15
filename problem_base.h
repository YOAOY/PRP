#ifndef BASE_PROBLEM__
#define BASE_PROBLEM__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// ----------------------------------------------------------------------
//		BProblem: the base class of problems (e.g. ZDT and DTLZ)
// ----------------------------------------------------------------------
class CIndividual;
struct Node
{
	string name;
    int number,demand,ready_time,due_time,service_time;
};

class BProblem
{
public:
	explicit BProblem(const std::string &name):name_(name) {}
	virtual ~BProblem() {}

	virtual std::size_t num_variables() const = 0;
	virtual std::size_t num_objectives() const = 0;
	virtual bool EvaluateDpCar(CIndividual *indv) const = 0;
	virtual bool Dp2Object(CIndividual *indv,int obj1_rate) const = 0;
	virtual bool EvaluateOldEncoding(CIndividual *indv) const = 0;
	

	const std::vector<Node> & node() const {return node_;}
	const std::vector<vector<double>> & dis() const { return distance_; }
	const std::vector<int> & ori_route() const { return ori_route_; }
	void PrintNode() const {cout << node_.size();}

	const std::string & name() const { return name_; }
	const std::size_t depot()const {return depot_section_;}
	const std::size_t maxload() const {return maxload_;}
	const std::size_t num_vehicles() const {return num_vehicles_;}
	const std::size_t lowest_speed() const { return lowest_speed_; }
	const std::size_t highest_speed() const { return highest_speed_; }
	const double avg_speed()const { return ((double)lowest_speed_ + (double)highest_speed_) / 2; }
	const std::size_t num_node() const { return num_node_; }

protected:
	std::string name_;
    std::vector<Node> node_;
	std::vector<vector<double>> distance_;
	std::vector<int> ori_route_;
	std::size_t depot_section_, curb_weight_,maxload_, dimension_ ,num_vehicles_,num_customers_,lowest_speed_,highest_speed_,num_node_;
	double feasible_dis_;
};

#endif
