# Table Generator

Table Generator is a cpp console application which takes XML file as a input and creates a HTML file(output.html) with the table created from the xml data.

This project was generated with [CLion 2023.1.2](https://www.jetbrains.com/clion/whatsnew/).

## How to Use

1. Download the XMLtoHTMLConverter.exe from the location.
2. Place the xml file in the same folder as exe file (if not, need to the give full path of the xml file).
3. Run the exe file and you will be seeing this text "Enter the XML file name :" on console window.
4. Now enter the file name and click on enter (ref below image).
<img width="431" alt="image" src="https://github.com/AiswaryaPatturaja2505/TableGenerator/assets/129544836/d385c77e-1b45-47c4-b8a6-8e2affa276f7">

5. Now you should be able to see a HTML file named **output.html**. This file will the table format of the XML data.

## Documentation

### Technologies Used.

**IDE** :  [CLion 2023.1.2](https://www.jetbrains.com/clion/whatsnew/)
**Language** :  CPP version 23.
**XML Parser** : [RapidXML](https://rapidxml.sourceforge.net/#:~:text=RapidXml%20is%20an%20attempt%20to,executed%20on%20the%20same%20data.)
 
### Design.

RapidXML is used to extract XML data from the input file, since it is the fastest XML parser possible, while retaining useability, portability and reasonable W3C compatibility.

Step 1: XML file to XML node objects.
Create a method the extracts the xml file content into xml nodes format.

Step 2: XML node to table data.
Based on the XML reference, we will be needing to extract root node <CATALOG>, list of its child (<cd>), name and value data of each child.
  
Step 3: HTML table Construction.
1. Create a string variable to store the HTML data.
2. Extract only first child of <CATALOG> whose child nodes comprises headers for table. Iterate the list with <th> tag enclose them with <tr> tag.
3. Now extract all the child of root node and iterate their values. Those values are made int <td> tags. Enclose all these tags with <table> tag.
  
Step 4 : Creating HTML file.
Add standard HTML, Header, body and style tags to the HTML table string. Now create a file named "output.html" and load the string to the file. <fstream> is used for file handling.
 
