// Copyright (C) 2009 by Florent Lamiraux, Thomas Moulard, AIST, CNRS, INRIA.
//
// This file is part of the roboptim.
//
// roboptim is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// roboptim is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with roboptim.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROBOPTIM_TRAJECTORY_TRAJECTORY_SUM_COST_HH
# define ROBOPTIM_TRAJECTORY_TRAJECTORY_SUM_COST_HH
# include <vector>
# include <roboptim/core/derivable-function.hh>

# include <roboptim/trajectory/fwd.hh>
# include <roboptim/trajectory/state-cost.hh>
# include <roboptim/trajectory/trajectory-cost.hh>

namespace roboptim
{
  template <typename T>
  class TrajectorySumCost : public TrajectoryCost<T>
  {
  public:
    typedef TrajectoryCost<T> parent_t;
    typedef T trajectory_t;
    typedef StateCost<T> stateCost_t;

    // FIXME: remove this.
    typedef typename parent_t::vector_t vector_t;
    typedef typename parent_t::gradient_t gradient_t;
    typedef typename parent_t::discreteInterval_t discreteInterval_t;

    TrajectorySumCost (const trajectory_t&, const stateCost_t&,
		       const vector_t&) throw ();
    TrajectorySumCost (const trajectory_t&, const stateCost_t&,
		       const discreteInterval_t&) throw ();

    virtual ~TrajectorySumCost () throw ();

    virtual vector_t operator () (const vector_t&) const throw ();
    virtual gradient_t gradient (const vector_t&, int) const throw ();

  protected:
    const stateCost_t& stateCost_;
    std::vector<double> points_;
  };

} // end of namespace roboptim.

# include <roboptim/trajectory/trajectory-sum-cost.hxx>
#endif //! ROBOPTIM_TRAJECTORY_TRAJECTORY_SUM_COST_HH