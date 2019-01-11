# OOP-Final

Test Procedure:

On application launch: 
•	Expect start dialog window labeled “WIT Person Database” to launch.
•	Dialog will have button-based options to “Add Entry”, “View Entry”, or “Quit”.
•	During initialization of the start dialog, the vector will be built from .txt file.

Select “Add Entry”: 
•	Expect new dialog window labeled “Add Entry” to launch in front of “WIT Person Database” starting window. 
•	The “Add Entry” dialog window will have button-based options to “Submit”, or “Cancel”.
•	The “Add Entry” dialog window will have 5 edit control boxes to enter “Name”, “Address”, “W-Number”, “Wage / Salary”, and “Hours / Salary Periods”
•	There will be three radio buttons to select role as either “Student, Staff or Faculty”.
•	You will only be able to select one radio button at a time.
•	Pressing “Submit” will create a new WIT Person based on the data entered in the control boxes and the selected role radio button.
•	The new Person will be added to the end of the vector.
•	Pressing submit will close “Add Entry Dialog”

Select “View Entries”
•	Expect new dialog window labeled “View Entries” to launch in front of “WIT Person Database” starting window. 
•	The “View Entries” dialog window will have button-based options “Next”, “Pay Me” or “Cancel”.
•	The “View Entries” dialog window will have 4 edit control boxes to display “Name”, “Address”, “W-Number”, and “Role”
•	On launch the first Person in the vector will be displayed in the control boxes.
•	Pressing “Next” will display the next Person in the vector.
•	Pressing “Next” on the last vector entry will close the “View Entries” Dialog.
•	Pressing “Cancel” will close the “View Entries” Dialog.
•	Pressing “Pay Me” will open a new dialog window titled “Pay Me”.

Select “Pay Me”
•	Expect new dialog window labeled “Pay Me” to launch in front of “View Entries” dialog window.
•	The “Pay” dialog window will have one button-based option “OK”.
•	The “View Entries” dialog window will have 4 edit control boxes to display “Name”, “Wage / Salary Rate”, “Hours / Salary Periods”, and “Gross Pay”.
•	On launch the calculations for the Person currently displayed in the “View Entries” dialog window will be displayed.
•	Pressing “OK” will close the “Pay Me” Dialog.

Select “Quit” (From Starting Dialog Window)
•	Expect all windows to close, and all changes made to vector to be reflected in “array.txt.”

