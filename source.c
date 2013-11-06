/*
 * File name:		Assignment8.c
 * Name:			Ashton Ansag
 * Course:			COP 1000 at Valencia College
 * Instructor:		David Stendel
 * Description:		This program takes the user's order displays a menu, total price, and items
 * Team Members:	Ashton, Charlie, and Manny
 * Date:			10/28/13
 */

// Preprocessor Directives
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// These are the prices for the order options
#define PRICE_HOT_DOG 2.00
#define PRICE_NACHOS 1.50
#define PRICE_POTATO_CHIPS 1.00
#define PRICE_MILK_SHAKE 2.50
#define PRICE_WATER 0.00

/*
 * Name:	main()
 * Input:   None.
 * Process: receiving input from user to take their order and when they are done it will total the cost with tax and display it back.
 * Output:  return 0 to indicate program ran complete.
 */

int main()
{
	char dollarSign = '$';
	// This checks the input entered for extras.
	int extra = 0;
	// These keep track of how many of each item is being ordered.
	int item1 = 0, item2 = 0, item3 = 0, item4 = 0, item5 = 0;
	// Keeps track of how many items are ordered.
	int itemsTotal = 0;
	// These tell which menu is in use. The next two check the input for order and remove.
	int ordering = 1, removing = 0, order = 0, remove = 0;
	// These keep track of how many items are ordered without extras.
	int item1Plain = 0, item2Plain = 0, item3Plain = 0, item4Plain = 0;
	// item# shows which item and Extra# shows which extra for that item and these variables keep track of how many orders with which extras.
	int item1Extra1 = 0, item1Extra2 = 0, item1Extra3 = 0, item2Extra1 = 0, item2Extra2 = 0, item2Extra3 = 0;
	int item3Extra1 = 0, item3Extra2 = 0, item3Extra3 = 0, item4Extra1 = 0, item4Extra2 = 0, item4Extra3 = 0;
	// These are running totals for each item.
	double total1 = 0.00, total2 = 0.00, total3 = 0.00, total4 = 0.00, total5 = 0.00;
	// Total is all of the above totals added together and final total is total * tax + total.
	double total = 0.00, tax = .075, finalTotal = 0.00, salesTax = 0.00;

	// This is a loop for the ordering menu.
	printf("Welcome to The Restaurant.\n");
	while (ordering == 1)
	{
		// This is a loop for the removing menu.
		while (removing == 1)
		{
			printf("Current Order:\n");
			if (item1 > 0)
			{
				printf("\n1. (%i) : Hot Dog", item1);
				// this if is to add an 's' to make the word plural if necessary.
				if (item1 > 1)
				{
					printf("s");
				}
				printf("\t %2c%5.2lf\n", dollarSign, total1);
			}
		
			if (item2 > 0)
			{
				printf("\n2. (%i) : Nachos \t %2c%5.2lf\n", item2, dollarSign, total2);
			}

			if (item3 > 0)
			{
				printf("\n3. (%i) : Potato Chips\t %2c%5.2lf\n", item3, dollarSign, total3);
			}
		
			if (item4 > 0)
			{
				printf("\n4. (%i) : Milkshake", item4);
				if (item4 > 1)
				{
					printf("s");
				}
				printf("\t %2c%5.2lf\n", dollarSign, total4);
			}
		
			if (item5 > 0)
			{ 
				printf("\n5. (%i) : Water", item5);
				if (item4 > 1)
				{
					printf("s");
				}
				printf("\t\t %2c%5.2lf\n", dollarSign, total5);
			}

			printf("Item to remove (0 returns to ordering menu):");
			scanf_s("%i", &remove);
			// This switch statement lets the user remove something from their order.
			switch (remove)
			{
				case 0:
					removing = 0;
					break;
				case 1:
					if (item1 > 0)
					{
						// Displays Hot Dogs Ordered and asking which one to remove.
						printf("\nHot Dog Order: \n");
						if (item1Extra1 > 0)
						{
							printf("   1.)  %i : Hot Dog w. Ketchup\n", item1Extra1);
						}
						if (item1Extra2 > 0)
						{
							printf("   2.)  %i : Hot Dog w. Mustard\n", item1Extra2);
						}
						if (item1Extra3 > 0)
						{
							printf("   3.)  %i : Hot Dog w. Ketchup & Mustard\n", item1Extra3);
						}
						if (item1Plain)
						{
							printf("   4.)  %i : Plain Hot Dog\n", item1Plain);
						}
						printf("   Any other # cancels removing order\n");
						printf("Remove: ");
						scanf_s("%i", &extra);
						// This switch uses input to decide which item to remove.
						switch (extra)
						{
							case 1:
								if (item1Extra1 > 0)
								{
									--item1Extra1;
									--item1;
								}
								break;
							case 2:
								if (item1Extra2 > 0)
								{
									--item1Extra2;
									--item1;
								}
								break;
							case 3:
								if (item1Extra3 > 0)
								{
									--item1Extra3;
									--item1;
								}
								break;
							case 4:
								if (item1Plain > 0)
								{
									--item1Plain;
									--item1;
								}
								break;
						}
					}
					// This else displays a message when they try to remove an item they have not ordered.
					else
					{
						printf(" ERROR NO HOT DOGS TO REMOVE \n");
						system("pause");
					}
					break;
				case 2:
					if (item2 > 0)
					{
						printf("\nNachos Order: \n");
						if (item2Extra1 > 0)
						{
							printf("   1.)  %i : w/ Jalapenos\n", item2Extra1);
						}
						if (item2Extra2 > 0)
						{
							printf("   2.)  %i : w/ Beef\n", item2Extra2);
						}
						if (item2Extra3 > 0)
						{
							printf("   3.)  %i : w/ Jalapenos & Beef\n", item2Extra3);
						}
						if (item2Plain > 0)
						{
							printf("   4.)  %i : Plain\n", item2Plain);
						}
						printf("   Any other # cancels removing order\n");
						printf("Remove: ");
						scanf_s("%i", &extra);
						switch (extra)
						{
							case 1:
								if (item2Extra1 > 0)
								{
									--item2Extra1;
									--item2;
								}
								break;
							case 2:
								if (item2Extra2 > 0)
								{
									--item2Extra2;
									--item2;
								}
								break;
							case 3:
								if (item2Extra3 > 0)
								{
									--item2Extra3;
									--item2;
								}
								break;
							case 4:
								if (item2Plain > 0)
								{
									--item2Plain;
									--item2;
								}
								break;
						}
					}
					else
					{
						printf(" ERROR NO NACHOS TO REMOVE \n");
						system("pause");
					}
					break;
				case 3:
					if (item3 > 0)
					{
						printf("\nPotato Chips Order: \n");
						if (item3Extra1 > 0) 
						{
							printf("   1.)  %i : Cheese Chips\n", item3Extra1);
						}
						if (item3Extra2 > 0)
						{
							printf("   2.)  %i : Baked Chips\n", item3Extra2);
						}
						if (item3Extra3 > 0)
						{
							printf("   3.)  %i : Barbecue Chips\n", item3Extra3);
						}
						if (item3Plain > 0)
						{
							printf("   4.)  %i : Plain Chips\n", item3Plain);
						}
						printf("   Any other # cancels removing order\n");
						printf("Remove: ");
						scanf_s("%i", &extra);
						switch (extra)
						{
							case 1:
								if (item3Extra1 > 0)
								{
									--item3Extra1;
									--item3;
								}
								break;
							case 2:
								if (item3Extra2 > 0)
								{
									--item3Extra2;
									--item3;
								}
								break;
							case 3:
								if (item3Extra3 > 0)
								{
									--item3Extra3;
									--item3;
								}
								break;
							case 4:
								if (item3Plain > 0)
								{
									--item3Plain;
									--item3;
								}
								break;
						}
					}
					else
					{
						printf(" ERROR NO POTATO CHIPS TO REMOVE \n");
						system("pause");
					}
					break;
				case 4:
					if (item4 > 0)
					{
						printf("\nMilkshake Order: \n");
						if (item4Extra1 > 0)
						{
							printf("   1.)  %i : Milkshake w/ Cherry\n", item4Extra1);
						}
						if (item4Extra2 > 0)
						{
							printf("   2.)  %i : Milkshake w/ Whipped Topping\n", item4Extra2);
						}
						if (item4Extra3 > 0)
						{
							printf("   3.)  %i : Milkshake w/ Cherry & Whipped Topping\n", item4Extra3);
						}
						if (item4Plain > 0)
						{
							printf("   4.)  %i : Plain Milkshake\n", item4Plain);
						}
						printf("   Any other # cancels removing order\n");
						printf("Remove: ");
						scanf_s("%i", &extra);
						switch (extra)
						{
							case 1:
								if (item4Extra1 > 0)
								{
									--item4Extra1;
									--item4;
								}
								break;
							case 2:
								if (item4Extra2 > 0)
								{
									--item4Extra2;
									--item4;
								}
								break;
							case 3:
								if (item4Extra3 > 0)
								{
									--item4Extra3;
									--item4;
								}
								break;
							case 4:
								if (item4Plain > 0)
								{
									--item4Plain;
									--item4;
								}
								break;
						}
					}
					else
					{
						printf(" ERROR NO MILK SHAKES TO REMOVE \n");
						system("pause");
					}
					break;
				case 5:
					if (item5 > 0)
					{
						--item5;
					}
					else
					{
						printf(" ERROR NO WATER TO REMOVE \n");
					}
					break;
			}
			// This is where the running totals get refreshed.
			total1 = item1 * PRICE_HOT_DOG;
			total2 = item2 * PRICE_NACHOS;
			total3 = item3 * PRICE_POTATO_CHIPS;
			total4 = item4 * PRICE_MILK_SHAKE;
			total5 = item5 * PRICE_WATER;
			itemsTotal = item1 + item2 + item3 + item4 + item5;
			total = total1 + total2 + total3 + total4 + total5;
			if (itemsTotal <= 0)
			{
				removing = 0;
			}
			system("CLS");


		}
		// Reset extra to 0 to avoid any errors.
		extra = 0;
		printf("MENU:\n");
		printf(" 1: Hot Dog \t%3c%5.2lf\n", dollarSign, PRICE_HOT_DOG);
		printf(" 2: Nachos \t%3c%5.2lf\n", dollarSign, PRICE_NACHOS);
		printf(" 3: Potato Chips%3c%5.2lf\n", dollarSign, PRICE_POTATO_CHIPS);
		printf(" 4: Milkshake \t%3c%5.2lf\n", dollarSign, PRICE_MILK_SHAKE);
		printf(" 5: Water \t%3c%5.2lf\n", dollarSign, PRICE_WATER);
		printf(" 0: Ends ordering\n");
		if (itemsTotal > 0)
		{
			printf("-1: Remove an order\n");
			printf("\nTotal so far:%6c%5.2lf\n", dollarSign, total);
			printf("Current Order:\n\n");
		}

		if (item1 > 0)
		{
			printf("\n%i : Hot Dog", item1);
			if (item1 > 1)
			{
				printf("s");
			}
			printf("\t %2c%5.2lf\n", dollarSign, total1);
			if (item1Extra1 > 0)
			{
				printf("	%i : w/ Ketchup\n", item1Extra1);
			}
			if (item1Extra2 > 0)
			{
				printf("	%i : w/ Mustard\n", item1Extra2);
			}
			if (item1Extra3 > 0)
			{
				printf("	%i : w/ Ketchup & Mustard\n", item1Extra3);
			}
			if (item1Plain)
			{
				printf("	%i : Plain\n", item1Plain);
			}
		}
		
		if (item2 > 0)
		{
			printf("\n%i : Nachos\t %2c%5.2lf\n", item2, dollarSign, total2);
			if (item2Extra1 > 0)
			{
				printf("	%i : w/ Jalapenos\n", item2Extra1);
			}
			if (item2Extra2 > 0)
			{
				printf("	%i : w/ Beef\n", item2Extra2);
			}
			if (item2Extra3 > 0)
			{
				printf("	%i : w/ Jalapenos & Beef\n", item2Extra3);
			}
			if (item2Plain > 0)
			{
				printf("	%i : Plain\n", item2Plain);
			}

		}

		if (item3 > 0)
		{
			printf("\n%i : Potato Chips %2c%5.2lf\n", item3, dollarSign, total3);
			if (item3Extra1 > 0)
			{
				printf("	%i : Cheese Chips\n", item3Extra1);
			}
			if (item3Extra2 > 0)
			{
				printf("	%i : Baked Chips\n", item3Extra2);
			}
			if (item3Extra3 > 0)
			{
				printf("	%i : Barbecue Chips\n", item3Extra3);
			}
			if (item3Plain > 0)
			{
				printf("	%i : Plain\n", item3Plain);
			}
		}
		
		if (item4 > 0)
		{
			printf("\n%i : Milkshake", item4);
			if (item4 > 1)
			{
				printf("s");
			}
			printf("\t %2c%5.2lf\n", dollarSign, total4);
			if (item4Extra1 > 0)
			{
				printf("	%i : w/ Cherry\n", item4Extra1);
			}
			if (item4Extra2 > 0)
			{
				printf("	%i : w/ Whipped Topping\n", item4Extra2);
			}
			if (item4Extra3 > 0)
			{
				printf("	%i : w/ Cherry & Whipped Topping\n", item4Extra3);
			}
			if (item4Plain > 0)
			{
				printf("	%i : Plain\n", item4Plain);
			}
		}
		
		if (item5 > 0)
		{ 
			printf("\n%i : Water", item5);
			if (item5 > 1)
			{
				printf("s");
			}
			printf("\t %2c%5.2lf\n", dollarSign, total5);
		}

		printf("\nItem wanted: ");
		scanf_s("%i", &order);
		// This switch adds the order the user requested or switches the loop to the remove menu.
		switch(order)
		{
			case -1 :
				if (itemsTotal > 0)
				{
					removing = 1;
				}
				break;
			case 0:
				ordering = 0;
				break;
			case 1:
				++item1;
				printf("\nHot Dog with:\n	1. Ketchup\n	2. Mustard\n	3. Both\n	(Any # for Plain)\nCondiment: ");
				scanf_s("%i", &extra);
				switch (extra)
				{
					case 1:
						++item1Extra1;
						break;
					case 2:
						++item1Extra2;
						break;
					case 3:
						++item1Extra3;
						break;
					default:
						++item1Plain;
						break;
				}
				break;
			case 2:
				++item2;
				printf("\nNachos with:\n	1. Jalapenos\n	2. Beef\n	3. Both\n	(Any # for Plain)\nExtra: ");
				scanf_s("%i", &extra);
				switch (extra)
				{
					case 1:
						++item2Extra1;
						break;
					case 2:
						++item2Extra2;
						break;
					case 3:
						++item2Extra3;
						break;
					default:
						++item2Plain;
						break;
				}
				break;
			case 3:
				++item3;
				printf("\nType of Chips:\n	1. Cheese Chips\n	2. Baked Chips\n	3. Barbecue Chips\n	(Any # for Plain)\nType: ");
				scanf_s("%i", &extra);
				switch (extra)
				{
					case 1:
						++item3Extra1;
						break;
					case 2:
						++item3Extra2;
						break;
					case 3:
						++item3Extra3;
						break;
					default:
						++item3Plain;
						break;
				}
				break;
			case 4:
				++item4;
				printf("\nMilkshake with:\n	1. Cherry\n	2. Whipped Topping\n	3. Both\n	(Any # for Plain)\nTopping: ");
				scanf_s("%i", &extra);
				switch (extra)
				{
					case 1:
						++item4Extra1;
						break;
					case 2:
						++item4Extra2;
						break;
					case 3:
						++item4Extra3;
						break;
					default:
						++item4Plain;
						break;
				}
				break;
			case 5:
				++item5;
				break;
			default :
				printf("ERROR NOT AN ORDER CHOICE\n");
				system("pause");
		}
		total1 = item1 * PRICE_HOT_DOG;
		total2 = item2 * PRICE_NACHOS;
		total3 = item3 * PRICE_POTATO_CHIPS;
		total4 = item4 * PRICE_MILK_SHAKE;
		total5 = item5 * PRICE_WATER;
		itemsTotal = item1 + item2 + item3 + item4 + item5;
		total = total1 + total2 + total3 + total4 + total5;
		system("CLS");
	}

	if (itemsTotal > 0)
	{
		salesTax = total * tax;
		finalTotal = total + salesTax;

		printf("Your final order:\n\n");	

		if (item1 > 0)
		{
			printf("%i : Hot Dog", item1);
			if (item4 > 1)
			{
				printf("s");
			}
			printf("\t %2c%5.2lf\n", dollarSign, total1);
			if (item1Extra1 > 0)
			{
				printf("	%i : w/ Ketchup\n", item1Extra1);
			}
			if (item1Extra2 > 0)
			{
				printf("	%i : w/ Mustard\n", item1Extra2);
			}
			if (item1Extra3 > 0)
			{
				printf("	%i : w/ Ketchup & Mustard\n", item1Extra3);
			}
			if (item1Plain)
			{
				printf("	%i : Plain\n", item1Plain);
			}

		}
		
		if (item2 > 0)
		{
			printf("%i : Nachos\t %2c%5.2lf\n", item2, dollarSign, total2);
			if (item2Extra1 > 0)
			{
				printf("	%i : w/ Jalapenos\n", item2Extra1);
			}
			if (item2Extra2 > 0)
			{
				printf("	%i : w/ Beef\n", item2Extra2);
			}
			if (item2Extra3 > 0)
			{
				printf("	%i : w/ Jalapenos & Beef\n", item2Extra3);
			}
			if (item2Plain > 0)
			{
				printf("	%i : Plain\n", item2Plain);
			}

		}

		if (item3 > 0)
		{
			printf("%i : Potato Chips %2c%5.2lf\n", item3, dollarSign, total3);
			if (item3Extra1 > 0)
			{
				printf("	%i : Cheese Chips\n", item3Extra1);
			}
			if (item3Extra2 > 0)
			{
				printf("	%i : Baked Chips\n", item3Extra2);
			}
			if (item3Extra3 > 0)
			{
				printf("	%i : Barbecue Chips\n", item3Extra3);
			}
			if (item3Plain > 0)
			{
				printf("	%i : Plain\n", item3Plain);
			}
		}
		
		if (item4 > 0)
		{
			printf("%i : Milkshake", item4);
			if (item4 > 1)
			{
				printf("s");
			}
			printf("\t %2c%5.2lf\n", dollarSign, total4);
			if (item4Extra1 > 0)
			{
				printf("	%i : w/ Cherry\n", item4Extra1);
			}
			if (item4Extra2 > 0)
			{
				printf("	%i : w/ Whipped Topping\n", item4Extra2);
			}
			if (item4Extra3 > 0)
			{
				printf("	%i : w/ Cherry & Whipped Topping\n", item4Extra3);
			}
			if (item4Plain)
			{
				printf("	%i : Plain\n", item4Plain);
			}
		}
		
		if (item5 > 0)
		{ 
			printf("%i : Water", item5);
			if (item4 > 1)
			{
				printf("s");
			}
			printf("\t %2c%5.2lf\n", dollarSign, total5);
		}
		// Outputs subtotal, sales tax, and end total
		printf("\n\n");
		printf("Subtotal\t%3c%5.2lf\n", dollarSign, total);
		printf("     Tax\t%3c%5.2lf\n", dollarSign, salesTax);
		printf("   Total\t%3c%5.2lf\n", dollarSign, finalTotal);
	}
	else
	{
		printf("***You didn't order anything.***\nThanks Anyways GOODBYE!\n");
	}
	system("pause");
	return 0;

}
