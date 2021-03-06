
#ifndef CROSSOVER__
#define CROSSOVER__

// ----------------------------------------------------------------------------------
//		CSimulatedBinaryCrossover : simulated binary crossover (SBX)
// ----------------------------------------------------------------------------------
class CIndividual;
class CSimulatedBinaryCrossover
{
public:
	explicit CSimulatedBinaryCrossover(double cr = 1.0, double eta = 30):cr_(cr), eta_(eta) {} // NSGA-III (t-EC 2014) setting

	void SetCrossoverRate(double cr) { cr_ = cr; }
	double CrossoverRate() const { return cr_; }
	void SetDistributionIndex(double eta) { eta_ = eta; }
	double DistributionIndex() const { return eta_; }

	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, double cr, double eta) const;
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2) const
	{
		return operator()(c1, c2, p1, p2, cr_, eta_);
	}

private:

	double get_betaq(double rand, double alpha, double eta) const;

	double cr_; // crossover rate
	double eta_; // distribution index
};


// ----------------------------------------------------------------------------------
//		CPartiallyMappedCrossover : Partially Mapped Crossover (PMX)
// ----------------------------------------------------------------------------------

class CPartiallyMappedCrossover
{
public:
    explicit CPartiallyMappedCrossover(double cr = 1.0) : cr_(cr){}

    void SetCrossoverRate(double cr) { cr_ = cr; }
    double CrossoverRate() const { return cr_; }

    bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, double cr) const;
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2) const
	{
		return operator()(c1, c2, p1, p2, cr_);
	}

private:
    double cr_; //crossover rate
};

// ----------------------------------------------------------------------------------
//		COrderedCrossover : Ordered Crossover (OX)
// ----------------------------------------------------------------------------------
class COrderedCrossover
{
public:
	explicit COrderedCrossover(double cr = 1.0) : cr_(cr) {}

	void SetCrossoverRate(double cr) { cr_ = cr; }
	double CrossoverRate() const { return cr_; }

	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, double cr) const;
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2) const
	{
		return operator()(c1, c2, p1, p2, cr_);
	}

private:
	double cr_; //crossover rate
};


// ----------------------------------------------------------------------------------
//		CLinearOrderedCrossover : Linear Ordered Crossover (LOX)
// ----------------------------------------------------------------------------------
class CLinearOrderedCrossover
{
public:
	explicit CLinearOrderedCrossover(double cr = 1.0) : cr_(cr) {}

	void SetCrossoverRate(double cr) { cr_ = cr; }
	double CrossoverRate() const { return cr_; }

	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, double cr) const;
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2) const
	{
		return operator()(c1, c2, p1, p2, cr_);
	}
	//me
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, double cr, double frank,double mrank) const;
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, double frank,double mrank ) const
	{
		return operator()(c1, c2, p1, p2, cr_,frank,mrank);
	}

private:
	double cr_; //crossover rate
};


#endif
