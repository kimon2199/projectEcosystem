# ecosystemSimulator
The project is a simulator for a functioning ecosystem. It contains areas of different soil where plants and animals live, grow, eat, fight and reproduce. A date tracking system and consequently a seasons tracking system are also simulated.

## 0 Usage
To compile use:
'make'
To run use:
'./ecosystemSimulator <terrain dimentions> <number of mountains> <days> <season>'
  ⋅⋅* '<terrain dimentions>' :rr
  ⋅⋅* '<number of mountains>' :rr
  ⋅⋅* '<days>' :rr
  ⋅⋅* '<season>' : rr

## 1 Ecosystem Description
The **Ecosystem** that is being simulated consists of a **terrain**, which is a square grid of **tiles** of a specified width (**terrainSize**). It containd the current day (**dayOfYear**) as well as a factor used to determine the "reproduction days" and "growth days". Every tile represents a different type of land and can be home to one kind of plant and however many types of animals. The types of land can be: water (**#**), hill (**^**) or plane (**"**).

## 1.1 Description of the Ecosystems Creation
Initially the ecosystem is created with the insertion of its size and the initial season of the simulation. After that the grid is generated (**MapGenerator**) in the following steps:
1. A river is created (**GenerateRiver**)
2. A lake is created (**GenerateLake**)
3. Two to four hills are generated in random spots (**GenerateHills**)
4. The rest of the terrain is turned into meadows (**GenerateMeadow**)
Next step of the simulation is placing the plants (**PlacePlants**). A predetermined number of plants are generated in random spots, following the restrictions of the soil type. The animals are generated in a similar fashion (**PlaceAnimals**). After that the simulation begins.

## 1.2 Plant Description
Plants are subdevided into two categories: The ones that contain seeds (**Seeded**) and the ones that don't (**Seedless**). The following plants contain seeds: **Oak**, **Pine** and **Maple** tree. The following plants don't contain seeds: **Grass** and **Algae**.
Every plant consists of a **name**, its coordinates (**x,y**) in the ecosytsem and a unique **token** to represent it. Also every type of plant has a different probability of reproduction (**breedingProb**) and probability of falling ill (**illnessProb**). Every plant has a **life** counter and dies when the counter reaches 0.

## 1.3 Animal Description
An animal is either a **Herbivore** (represented by **"H"**) or a **Carnivore** (represented by **"C"**).
The following animals are herbivores: **Deer**, **Rabbit**, **Groundhog** and **Salmon**. The following animals are carnivores: **Fox**, **Bear** and **Wolf**.
Every animal consists of a **name**, a **size**, the number of days it has not eaten (**hungerCount**), its coordinates (**x,y**), its **speed** and a number of flags indicating whether it's alive or dead (**isAlive**), if it's hungry or not (**isHungry**), if it's its reproduction period (**inHeat**), wheather it can hibernate or not (**hibernates**) and if it's currently hibernating (**inHibernation**). An animal can **Move**, **Eat** and grow (**Raise**). An animal has reached adulthood when its size has reached the maximum for its animal type.

### 1.3.1 Herbivore Description
Each herbivores has two aditional characteristics: a flag for wheather it can climb or not (**canClimb**) and the amount of food it needs (**neededFood**). When a herbivore eats a plant it adds a specific amount of food (**eatCount**) to the food it has consumes (**eatenFood**) until it is full and has reached the max food for the day (**neededFood**). If it eats a seedless plant, the amount is removed from the plants life (**LoseLife**). If it eats a seeded plant, if it still has fruit the amount is removed from the fruit else it is removed from the foliage and the plants life (**LoseLife**).

### 1.3.2 Carnivore Description
A carnivore has two extra characteristics: its **attack** and its **defence**. When a carnivore has a meal it becomes full regardless of what kind of animal it has eaten.
