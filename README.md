#### <center>Defining the DataContext</center>

Data binding works in a **DataContext**, before every thing is started, we must define the DataContext. **DataContext must be a object, this object is the "ViewModel" of our GUI and all the data bindings will be done on this object.** If the data we use are not all combined into one class but exist as our MainWindow's properties, we set the DataContext to be the MainWindow it self:

```c#
public MainWindow()
{
      InitializeComponent();
      DataContext = this;
}
```

#### <center>Defining the Binding Path</center>

**All the data we are going to bind to the GUI must be the properties of this DataContext.** 

Now we are binding some data to a ListBox in MainWindow.xaml:

```html
<ListBox x:Name="listBox" ItemsSource="{Binding Names}"/>
<ListBox x:Name="listBox" ItemsSource="{Binding Path=Names}"/>
```

The two lines of xaml code above are the same, the so called "Path" means the path of the data we are going to bind relative to DateContex, so we can understand it as binding the ItemsSource to DataContex.Names. **"Names" is a property of the DataContex, in our case, it is *this.Names***, which means there must be a property "Names" existed in our MainWindow class:

```c#
public partial class MainWindow : Window
{
	public ObservableCollection<string> Names { get; set; }
	public MainWindow()
	{
      	  Names = new ObservableCollection<string>() { "hehe", "haha" };
    	  InitializeComponent();
      	  DataContext = this;
	}
}
```

Because we are binding some data to a ListBox, this data(property) must be some kinds of Collection. In order to synchronize between data and ListBox, **it must be ObservableCollection**, what's more, **it must be a public property and has explicit "get" and "set".**

If it is not a ObservableCollection, the ListBox can not notice its changes. 

If it is not public, the ListBox can not get access to it.

Now the program should run correctly. Except defining the DataBinding in xaml, we can also achieve the same functionality dynamically in the code:

```c#
listBox1.ItemsSource = Names;
```

**Attention, when the ItemsSource is defined, the ListBox's traditional data model ListBox.Items can no longer be used. The Items is now null, so when you try to do Items.Add, Items.Remove etc.. you will get an exception.**

The result of data binding is **you can and only can work on the data**, the GUI, in our case the ListBox, will synchronize by itself and we don't need to care about it anymore.

#### <center>Bind SelectedItem</center>

If we want to bind the ListBox's selected item to some data, it is also possible:

The xaml way:

```html
<ListBox x:Name="listBox" ItemsSource="{Binding Names}" SelectedItem="{Binding selectedName, Mode=TwoWay}"/>
```

Of cause we have to add a property named "selectedName" in our DataContex(MainWindow):

```c#
public partial class MainWindow : Window
{
	public ObservableCollection<string> Names { get; set; }
    public string selectedName { get; set; }
  	...
}
```

The C# way:

```c#
listBox1.SetBinding(ListBox.SelectedItemProperty, new Binding("selectedName"));
```

#### <center>More complicated case: bind object list</center>

Now we are binding a collection of string to a ListBox, what if we want to bind a collection of objects? Some tiny things have to be changed:

Change the data to :

```c#
public class Person
{
    public Person(string n, int a)
    {
    	Name = n;
        Age = a;
    }
	public string Name {get;set;}    
    public int Age {get;set;}    
}
public partial class MainWindow : Window
{
	public ObservableCollection<Person> Persons { get; set; }
    public string selectedName { get; set; }
	public MainWindow()
	{
         Persons = new ObservableCollection<Person>();
         Persons.Add(new Person("Lena",18));
      	 InitializeComponent();
      	 DataContext = this;
    }
}
```

So we can see that Person as a class of cause can not be directly presented by ListBox, so we should set the ListBox's DisplayItemPath in xaml:

```html
<ListBox x:Name="listBox" ItemsSource="{Binding Persons}" DisplayMemberPath="Name"/>
```

Which means we want to display DataContext.Persons[k].Name as the ListBox's kth item. In this case the kth item will display ***this.Persons[k].Name.***

------

All code Combined

C# Part:

```c#
public partial class MainWindow : Window
{
        public ObservableCollection<string> Names { get; set; }
        public string selectedName { get; set; }
        public MainWindow()
        {
            Names = new ObservableCollection<string>() { "hehe", "haha" };
            InitializeComponent();
            DataContext = this;
        }
}
```

XAML Part:

```html
<Window x:Class="DataBinding.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:DataBinding"
        mc:Ignorable="d"
        Title="MainWindow" Height="350" Width="400.838">
    <Grid Margin="0,0,4,-0.2">
        <ListBox x:Name="listBox" ItemsSource="{Binding Names}" SelectedItem="{Binding selectedName, Mode=TwoWay}"/>
    </Grid>
</Window>
```
