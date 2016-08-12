import java.util.*;
import java.io.*;

class Address
{
  public String street;
  public String town;
  public String state;
  public String zip;
  
  public Address()
  {
    street = "";
    town = "";
    state = "";
    zip = "";
  }
  
  public Address(String street, String town, String state, String zip)
  {
    this.street = street;
    this.town = town;
    this.state = state;
    this.zip = zip;
  }
  
  public String getZip()
  {
    return this.zip;
  }
  
  public String toString()
  {
    String s = this.street + ", " + this.town + ", " + this.state + ", " + this.zip;
    return s;
  }
}

class House extends Address
{
  public Address address;
  public int area;
  public int bedRooms;
  public int bathRooms;
  public int garage;
  public double price;
  
  public House()
  {
    address = null;
    area = 0;
    bedRooms = 0;
    bathRooms = 0;
    garage = 0;
    price = 0;
  }
  
  public House (Address address, int area, int bedRooms, int bathRooms, int garage, double price)
  {
    this.address = address;
    this.area = area;
    this.bedRooms = bedRooms;
    this.bathRooms = bathRooms;
    this.garage = garage;
    this.price = price;
  }
  
  public double getPrice()
  {
    return this.price;
  }
  
  public int getArea()
  {
    return this.area;
  }
  
  public int getBedRooms()
  {
    return this.bedRooms;
  }
  
  public String toString()
  {
    String s = "(" + this.address + ", " + this.area + ", " + this.bedRooms + ", " + this.bathRooms + ", " + this.garage + ", " + this.price + ")";
    return s;
  }
  
  public double priceSqft()
  {
    double priceSqFt = this.price / this.area;
    return priceSqFt;
  }
}

class HouseList
{
  public House[] houseList;
  private int numHouses = 0;
  
  public HouseList()
  {
     houseList = new House[0];
  }
  
  public void HouseList(int n)
  {
    houseList = new House[n];
    numHouses = n;
  }
  
  public int getNumHouses()
  {
    return numHouses;
  }
  
  public void searchByZip (String zip)
  {
    for (int i = 0; i < houseList.length; i++)
    {
      if (houseList[i].address.getZip().equals(zip))
      {
        System.out.println(houseList[i].toString());
      }
    }
  }
  
  public void searchByPrice (double lowPrice, double highPrice)
  {
    for (int i = 0; i < houseList.length; i++)
    {
      if ((houseList[i].getPrice() >= lowPrice)&&(houseList[i].getPrice() <= highPrice))
      {
        System.out.println(houseList[i].toString());
      }
    }
  }
  
  public void searchByArea (int lowArea, int highArea)
  {
    for (int i = 0; i < houseList.length; i++)
    {
      if ((houseList[i].getArea() >= lowArea)&&(houseList[i].getArea() <= highArea))
      {
        System.out.println(houseList[i].toString());
      }
    }
  }
  
  public void searchByRooms (int rooms)
  {
    for (int i = 0; i < houseList.length; i++)
    {
      if (houseList[i].getBedRooms() == rooms)
      {
        System.out.println(houseList[i].toString());
      }
    }
  }
}

public class Realtor
{
  public static void main ( String[] args ) throws IOException
  {
    Scanner sc = new Scanner (new BufferedReader(new FileReader("realtor.txt")));
    Scanner userSC = new Scanner (System.in);
    
    // Create a HouseList object that can hold a hundred houses
    HouseList HouseList = new HouseList();
    HouseList.HouseList(100);

    // Populate the array with 10 houses with data from realtor.txt
    for (int i = 0; i < 10; i++)
    {
      Address address = new Address (sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
      House h = new House(address, sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextDouble());
      HouseList.houseList[i] = h;

      if (i != 9)
      {
        sc.nextLine();
        sc.nextLine();
      }
    }

    // Write out the number of houses in your list
    System.out.println(HouseList.getNumHouses());
    System.out.println("");

    System.out.println(HouseList.houseList[0].getZip());
    /*
    // Write out the houses in a certain zip code
    String s = userSC.next();    
    HouseList.searchByZip(s);
    System.out.println("");

    // Write out the houses in a certain price range
    HouseList.searchByPrice(userSC.nextDouble(), userSC.nextDouble());
    System.out.println("");

    // Write out the houses in a certain square foot range
    HouseList.searchByArea(userSC.nextInt(), userSC.nextInt());
    System.out.println("");

    // Write out the houses that have a certain number of bedrooms
    HouseList.searchByRooms(userSC.nextInt());
    System.out.println("");
    */
  }
}
