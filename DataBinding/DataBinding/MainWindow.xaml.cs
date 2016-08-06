using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace DataBinding
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    public partial class MainWindow : Window
    {
        public ObservableCollection<string> Names { get; set; }
        public string selectedName { get; set; }
        public MainWindow()
        {
            Names = new ObservableCollection<string>() { "hehe", "haha" };
            InitializeComponent();
            //At this point, listbox.itemsource is not ready
            this.Loaded += MainWindow_Loaded;    
            DataContext = this;
            //Programmatically binding
            listBox1.ItemsSource = Names;
            listBox1.SetBinding(ListBox.SelectedItemProperty, new Binding("selectedName"));
        }

        private void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {//The listbox.itemsource is now ready
            (listBox.ItemsSource as ObservableCollection<string>).Add("lala");
        }

        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            string selected = selectedName;
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            Names.RemoveAt(0);
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            (listBox.ItemsSource as ObservableCollection<string>).Add("oh my god");
            Names.Add("oh my lord");
        }
    }
}
