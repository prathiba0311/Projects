package librarymgmt;

import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.text.SimpleDateFormat;

class Student{
	
	String id;
	String title;
	
	Calendar bdate;
	Calendar rdate;
	SimpleDateFormat sdf;
	
	String borrowdate,returndate;
	
	int ans;
	int fine=0;
	
	Student()
	{
		title = null;
		sdf = new SimpleDateFormat("dd MMM YYYY");
		bdate = new GregorianCalendar();
		rdate = new GregorianCalendar();
		rdate.add(Calendar.DAY_OF_MONTH, +15);
		borrowdate = sdf.format(bdate.getTime());
		returndate = sdf.format(rdate.getTime());
	}
	
}
class Book{
	String name;
	boolean availability;
	Book(String name){
		this.name=name;
		availability =true;
	}
	boolean checkAvailability(){
		return availability;
	}
	String printAvailability() {
		if(availability)
			return "yes";
		else
			return "no";
	}
}


public class library extends Student{

	public static void main(String[] args) {// TODO Auto-generated method stub
		
		Scanner in=new Scanner(System.in); 
		Student student=new Student();
		Book[] b = new Book[5];
		b[0]=new Book("harry_potter");
		b[1]=new Book("divergent");
		b[2]=new Book("twilight");
		b[3]=new Book("percy_jackson");
		b[4]=new Book("secret_series");
		
		String users[] = {"user1","user2","user3","user4","user5","user6"};
		String passes[] = {"pass1","pass2","pass3","pass4","pass5","pass6"};
		
		
		boolean access = true;
		while(true)
		{
			System.out.print("Enter your username  : ");
			
			student.id=in.next();
			System.out.print("Enter your password  : ");
			String pass = in.next();
			access=check(users,passes,student.id,pass);
			
			while(!access) {
				System.out.println("Invalid Password! Try again!");
				System.out.print("Enter your username  : ");
				
				student.id=in.next();
				System.out.print("Enter your password  : ");
				pass = in.next();
				access=check(users,passes,student.id,pass);
			}
			
			while(access)
			{
				System.out.println("Welcome");
				System.out.println("1. Take a book");
				System.out.println("2. Return a book");
				System.out.println("3. List of books");
				System.out.println("Enter your choice : ");
				
				student.ans=in.nextInt();
				
				if(student.ans==1)
				{
					System.out.println("Enter the name of the book : ");
					student.title=in.next();
					if(check_book(b,student.title))
					{
						if(b[book_index(b,student.title)].checkAvailability())
						{
							System.out.println("Date of borrowing: "+ student.borrowdate);
							System.out.println("Date of returning: "+ student.returndate);
							b[book_index(b,student.title)].availability=false;
						}
						else
						{
							System.out.println("This book is not available");
						}
					}
					else
					{
						System.out.println("This book is not available");
					}
					
				}
				
				else if(student.ans==2 && student.title!=null)
				{
					
					System.out.println("Enter the date at which you took the book ");
					int dd,mm,yy;
					System.out.println("Enter the date(dd): ");
					dd = in.nextInt();
					System.out.println("Enter the month(MM): ");
					mm = in.nextInt();
					System.out.println("Enter the year(YYYY): ");
					yy = in.nextInt();
					
					Calendar dateofreturn = new GregorianCalendar(yy,mm-1,dd);
					Calendar curdate = new GregorianCalendar();
					dateofreturn.add(Calendar.DAY_OF_MONTH, +15);
					SimpleDateFormat sdf = new SimpleDateFormat("dd MMM YYYY");
					System.out.println("Official Return Date : " + sdf.format(dateofreturn.getTime()));
					System.out.println("Actual Return Date: " + sdf.format(curdate.getTime()));
					
					student.fine = curdate.get(Calendar.DAY_OF_MONTH) - dateofreturn.get(Calendar.DAY_OF_MONTH);
					student.fine += (curdate.get(Calendar.MONTH) - dateofreturn.get(Calendar.MONTH))*30;
					student.fine += (curdate.get(Calendar.YEAR) - dateofreturn.get(Calendar.YEAR))*365;
					
					if(student.fine<0)
						student.fine = 0;
					System.out.println("You have to pay a fine of: Rs. " + student.fine);
					
					for(int i=0 ; i<5 ; ++i)
						if(b[i].name.compareTo(student.title)==0)
							b[i].availability = true;
					student.title = null;
				}
				else if(student.ans==2 && student.title==null)
					System.out.println("Borrow a book first");
				else if(student.ans==3) {
					for(int i=0;i<5;i++) {
						System.out.println("Name : " + b[i].name+"\nAvailablity : "+b[i].printAvailability());
					}
				}
				String choose;
				System.out.println("Do you want to continue yes or no?");
				choose=in.next();
				if(choose.compareTo("no")==0)
					break;
			}
		}
	}
	public static boolean check(String[] u,String[] p,String user,String pass) {
		for(int i =0;i<u.length;i++)
			if(user.compareTo(u[i])==0)
				if(pass.compareTo(p[i])==0)
					return true;
		return false;
	}
	public static boolean check_book(Book u[],String x)
	{
		for(int i =0;i<u.length;i++)
			if(x.compareTo(u[i].name)==0)
				return true;
		return false;
	}
	public static int book_index(Book u[],String x)
	{
		for(int i =0;i<u.length;i++)
			if(x.compareTo(u[i].name)==0)
				return i;
		return -1;
	}
	
}
