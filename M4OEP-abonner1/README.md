#Match the Slime to their favorite food!
Aidan Bonner
#Summary
The program uses polymorphism and inheritance, both in the is-a and has-a relationship form.
The Slime abstract class contains the name field and its getter and setter, as well as the pure virtual method feed.
Its subclasses, EverythingSlime, FavoriteSlime, and UniqueDiet Slime, each eat different things, and so implement the feed method in unique ways.
- EverythingSlime will eat all non-unique foods that are not nothing, but have no favorite, and so the feed method can only return 1 or 0
- FavoriteSlime will only eat  food of a specific type, and have a favorite within that type, so the feed emthod will either return 0 fro the wrong type, 1 for the right type, or 2 for the favorite food
- UniqueDietSlime will eat only unique foods, which do not actually count as favorites, and so feed will only return 1 if the unique food is the correct one, or 0 otherwise
SlimeMatcher is the skeleton of the game, allowing for matches to be guessed and for choices to be validated.  
The bulk of the game is implemented in main using the guess and validator methods from SlimeMatcher to ask the user to choose a slime from the list displayed, and then a food from the list, and make a guess using that slime and food.
After the guess has been amde, the slime, but not the food, is removed from the game, disallowing duplicate guesses, but the food is not.
This repeats until the slime column is empty, and the game is finished, at which point, the number of points earned and the number of plorts earned are displayed.
#Known bugs
- The code will not compile
  - This is mostly because the guess method in SlimeMatcher takes a Slime object, which the IDE is fine with until compile time,when it recognizes it as an abstract class and refuses to compile
  - There also appear to be issues with the pointers, but the compiler error messages are unclear, and it is entirely likely they are further results of the issues SLime's abstractness is causing
#Future Work
- get the code to work literally at all
  - add a testing function once it can compile
- Finish implementing the game to function in the console
  - The while loop representing the actual game should be moved to SlimeMatcher so that, ideally, main can be reduced in size
    - SlimeMatcher could be modified to create the vectors by reading them in from a file, so that the main program could theoretically be reduced even further in size
- Change the type field in Food from a string to an enumerated type containing everything, nothing, unique, meat, veggie, and fruit
- Implement the game itself outside of the console
  - Change the guess functionality from entering strings in the console to clicking on and dragging a Food to the desired Slime
- Implement a running tally for the score that can update after each guess and be displayed during the game
#Grade Expected
25
This project, frankly, doesn't have much going for it.  It won't even compile.  But, it has three uses of the Is-A class relationship in Slime and its subclasses, and a Has-A relationship in both FavoriteSlime and its favorite food, and SlimeMatcher and its vectors of Food and SLime pointers.
So I'm going to be optimistic and say that the implementation of those relationships is sufficiently robust and useful to warrant full points.
No points will be awarded for main or the testing program, given that they don't run, meaning the video, despite being included, can't have a demo run, costing 5 of the 40 points, and then, while I think the organization of the code is clear and logical, the comments are likely lacking, presumably costing ten more points.
Obviously the bulk of the actual coding has taken place in a small period of time, relative to the length of the module, but I do think the earlier contributions show that significant but ultimately insufficient work has been done over more than 3 days, and the commits do span a week.
