using System;
using System.Text;
using System.Collections.Generic;


namespace sort {
	 class sorter{
	       static void Main(string[] args) {
		      //This will contain all the words in one string
		      string str = "";
		      string word = "";
		      string input = Console.ReadLine();
		      while ((input = Console.ReadLine()) != null && input != ""){
		            str += (input + " ");
		      } 	 
		      //This makes that string into an array by splitting it using the spaces
	       	       string[] arr = str.Split();

		       //Goes through all the words 
		       for (int i = 0; i < (arr.Length-1); i++){

				//Actually sorting through the words and checking the order
				if (string.Compare (arr[i], arr[i+1]) < 0){
					word = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = word;
				}
				
			}

		       for (int i = 0; i < arr.Length; i++){
		       	   Console.WriteLine(arr[i]);
		       }
		}
	}
	
}