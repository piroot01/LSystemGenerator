# LSystem genrator TO-DO list (notes)

## Types of the systems

### DOL-system

 - simplest just ordered triplet alphabet, axiom and rules

### Stochastic system

 - ordered quadruplet, DOL plus mapping function which maps each rule to its propability (sum of them is 1)
 - they could be further splitted into two categories:
  - step/angle randomization (done using some distribution function, deviation, ...)
  - rule choice randomization

### Context sensitive system

 - ordered quadruplet, same as DOL but it adds formal parameters < and >

 1. 1L-system
  - only left or right context
  - p1: A < a -> A
  - p2: A -> a
 
 2. 2L-system
  - could be from both sides


### Parametric system

 1. Parametric OL-system

  - ordered quadruplet, alphabet, set of formal parameters, axiom, set of production rules
  - here the production rules can be little bit tricky:
   - it could consists from logical expressions and arithmetic expressions
  - p1: B(t) : t <= 5 -> B(t - 2)

 2. Parametric 2L-system
  - same as above but it can also react to the context from the both sides

 3. Parametric stochastic system
  - could randomize the parameter based on the probalistic function

 4. Parametric stochastic 2L-system
  - basically all together :D
