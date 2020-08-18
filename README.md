# cs250_projectRedux -- Settlers BuildOut and Unit Testing Plan

## Stage 1: main and GameStatus

### 1.0: main with CLAs converted to ints
- debug output for CLAs
- initialize variables

### 1.0.1: Create GameStatus Class
- receive pointers:
	- resource change array (already a pointer)
	- player1x score
	- player2y score
	- turns

### 1.0.2: Create dummy player resource data (just in main or gamestatus)
- for testing resource updates


### 1.0.3 **Create basic (dummy class objects for all)**
- test to make sure they work

### 1.1: Loop through game until score is 6
- Add mock inputs for score
- Debug output for score and turns

### 1.2: Add debug utilities
- Debug print
	- Debug for resource array on heap
- Horizontal line
- Screen reset (multiplatform)

### 1.3: Validate char and int inputs --DONE Chars Both--
- Generic inputs
- Debug out

### 1.4: Updating resource array
- Input from CLAs
- Figure out which player based on turns
- Confirm positive, zeros, negatives
- Use Debug output

### 1.5: Official Outputs
- Winning message -- Doneish--
- Score official output
- Available Resources

### 1.6: Action Choice
- Action choice prompt
- Valid choice
- Output int (debug out)

## Stage 2: Board

### 2.0: Create Board Class
- see other docs for class member list
- parameters for constructor: pointers to turns, scores
- include outputs

### 2.1: Create basic grid with dummy resources
- Output basic grid with proper dimensions
- Include grid numbers on left and top margins

### 2.2: Create resourceBlocks with random chars
- Create resourceBlocks when initializing board object
	- Randomly generate characters
- Output
- Make sure they update every game

### 2.3: Create test settlement
- input dummy player #
- input dummy coordinates Y, X
- output to board with appropriate player symbol - test both
	- test corners
 2.6: Sum resources at given settlement
 - Pull resources from adjacent cells -> must match a resource char


#### 2.6.1: Modify resource array (main)
 - Debug output -> display contents of array update link

### 2.4: Create test road
- input dummy coordinates
- output to board - test middle, and perimeters (all 4)
- correct orientation

### 2.5: Validate build request coordinates
- Input from CLA
- Check that coordinates are in valid range (use valid int from earlier)
- Return t/f

#### 2.5.1: Road or settlement
- debug output -> road or settlement

#### 2.5.2: Create dummy settlements
- create linked list of settlements	
	- linked list containing int array of 3: Y,X,Owner
	- test corners, perimeters, and middle
	- test both players
- debug output

#### 2.5.3: Create dummy roads
- create linked list of roads
	- linked list containing int array of 2: Y,X Coordinates
	- test perimeters
	- make sure orientation is correct
- Debug output (bad position)

#### 2.5.4: Check neighborhood for new settlement
- request with CLAs (coords and player number) 
	- debug function to grab and transmit where it needs to go
- check dummy settlements to ensure not too close -- return false if it is
	- also check that settlement isn't already there
- check dummy roads to make sure there's a connection to proposed settlement
- **if valid -> create new linked list element at coordinates and player#**
- Check proper output: position, symbol
- Check beside preexisting, check where there isn't a road, check corner and perimeter (esp right wall and bottom)
- Debug output (building already here, too close to existing settlement, no road connection)

#### 2.5.5: Increment score
- After valid settlement build -> increment score 

#### 2.5.6: Check neighborhood for new road
- Check adjacent cells for road
- Check that road doesn't already exist
- **if valid -> create new linked list element at coordinates of road**
- edit cell to proper road symbol  -- use same function as dummy road

### 2.6: Sum resources at given settlement
- Pull resources from adjacent cells -> must match a resource char

#### 2.6.1: Modify resource array (main)
- Replace resource array of main with new values
	- Board should have a pointer to this
- Debug output -> display contents of array 

## Player

### 3.1 Initialize players (in main)
- pointers to turns
- pointer to resource change array
- Constructor (simple)
- Resources (0)
- Wages (0)

### 3.1.1: Update wage and/or resource array (income, new building, etc.)
- Use extra parameter to dictate: wage update (2), resource update (1), --> overload for trade pass two ints (out, in)
- Take in resource change array or wages
- Check turn to pick player
- Run through change array and apply to appropriate array (wage or res)
- Debug output for this transaction (begin, in, out, end)

### 3.2: Perform trade
- Prompt
- Validate char entrys -- don't forget to clear if needed
- Call Trade with two parameters (int pay, int get)
	- These will be indexes for resource array

#### 3.2.1: Check trade inputs/payment
- Check avaible input/payment resource against resource array.
- if ok -> withdraw 3 of payment and add 1 to resource
- if not ok -> return false
	- reprompt for action choice
- debug output of player's new resources

### 3.3: Issue wages
- At start of turn > 2 AND modulo 2 = 0 (once per round)
- Add player's wages to current wages using update wage/resource function
- Perform a loop of two that'll cover both players -- non-member function...
- Pass player object as a parameter to this function

### 3.4: Update wages
- Check resource array
- Check turn# to pick appropriate player
- Add new items to wages with loop
- Debug out the wages






