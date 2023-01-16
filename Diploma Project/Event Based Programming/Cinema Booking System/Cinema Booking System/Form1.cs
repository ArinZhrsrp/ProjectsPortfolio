using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cinema_Booking_System
{
    public partial class Form1 : Form
    {
        string movieName;
        string scheduleMovieName1;
        string hallName;
        int movieId;
        DateTime scheduleTime;
        int hallId;
        string scheduleHallName;
        DateTime scheduleDate;
        decimal schedulePrice;
        int scheduleId;

        public Form1()
        {
            InitializeComponent();

            dateTimePicker2.Format = DateTimePickerFormat.Custom;
            dateTimePicker2.CustomFormat = "hh:mm tt";
        }

        SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");

        private void Form1_Load(object sender, EventArgs e)
        {
            SqlDataAdapter sda = new SqlDataAdapter("select * from movieTable", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            foreach(DataRow dr in dt.Rows)
            {
                movieName = dr["movieName"].ToString();
                comboBoxMovieName.Items.Add(movieName);
            }

            refresh();
        }

        //for messagebox show 
        Action<string> display = print => MessageBox.Show(print);
        //delegate
        public delegate void gathering(string movieName, DateTime date, DateTime time, string hall, decimal price);
        public delegate int SearchMovie_ID(string ID);
        public delegate DateTime set_Date(DateTime date);
        public delegate DateTime set_Time(DateTime time);
        public delegate int SearchHall_ID(string ID);
        public delegate decimal Price(decimal price);

        private void buttonSave_Click(object sender, EventArgs e)
        {
            try
            {
                //using delegate
                gathering gather = Gather;
                gather(comboBoxMovieName.SelectedItem.ToString(), dateTimePicker1.Value.Date, dateTimePicker2.Value, comboBoxHall.SelectedItem.ToString(), decimal.Parse(textBoxPrice.Text));

                string insert = "Insert into scheduleTable (movieId, hallId, scheduleDate, scheduleTIme, schedulePrice) values ('" + movieId + "', '" + hallId + "', '" + scheduleDate.ToString("yyyy-MM-dd") + "', '" + scheduleTime + "', '" + schedulePrice + "')";

                sqlcon.Open();
                SqlCommand cmd = new SqlCommand(insert, sqlcon);
                cmd.ExecuteNonQuery();
                sqlcon.Close();

                display("Changes saved.");

                SqlDataAdapter sda = new SqlDataAdapter("select scheduleId [ID], movieName [Movie], hallName [Hall], scheduleDate [Date], scheduleTime [Time], schedulePrice [Price] from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId inner join movieTable on movieTable.movieId = scheduleTable.movieId order by scheduleDate", sqlcon);
                DataTable dt = new DataTable();
                sda.Fill(dt);

                dataGridView1.DataSource = dt;

                checkHall();
            }
            catch
            {
                display("Changes saved.");
            }
        }

        //gather inform from design form1
        public void Gather(string movieName, DateTime date, DateTime time, string hall, decimal price)
        {
            //insert movie
            movieId = searchMovie(movieName);
            //insert date
            scheduleDate = setDate(date);
            //insert time
            scheduleTime = setTime(time);
            //insert hall
            hallId = searchHall(hall);
            //insert price
            schedulePrice = price_(price);
        }

        SearchMovie_ID searchMovie = ID =>
        {
            SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");
            int movieID = 0;
            SqlDataAdapter sda1 = new SqlDataAdapter("select movieId from movieTable where movieName = '" + ID + "'", sqlcon);
            DataTable dt1 = new DataTable();
            sda1.Fill(dt1);
            //search movie id
            foreach (DataRow dr1 in dt1.Rows)
            {
                movieID = int.Parse(dr1["movieId"].ToString());
            }
            return movieID;
        };

        set_Date setDate = date =>
        {
            DateTime scheduleDate =
            scheduleDate = date;
            return scheduleDate;
        };

        set_Time setTime = time =>
        {
            DateTime scheduleTime;
            DateTime dte = time;
            dte.ToString("t");
            scheduleTime = dte.AddSeconds(-dte.Second);

            return scheduleTime;
        };

        SearchHall_ID searchHall = ID =>
        {
            SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");
            int hallID = 0;

            SqlDataAdapter sda2 = new SqlDataAdapter("select hallId from hallTable where hallName = '" + ID + "'", sqlcon);
            DataTable dt2 = new DataTable();
            sda2.Fill(dt2);
            //find hall id
            foreach (DataRow dr2 in dt2.Rows)
            {
                hallID = int.Parse(dr2["hallId"].ToString());
            }
            return hallID;
        };

        Price price_ = price =>
        {
            decimal pricetiket = price;
            return pricetiket;
        };

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            scheduleDate = dateTimePicker1.Value.Date;
            Gather(scheduleMovieName1, scheduleDate, scheduleTime, scheduleHallName, schedulePrice);

            checkHall();
        }

        private void dateTimePicker2_ValueChanged(object sender, EventArgs e)
        {
            DateTime dte = dateTimePicker2.Value;
            dte.ToString("t");

            scheduleTime = dte.AddSeconds(-dte.Second);

            checkHall();
        }

        private void checkHall()
        {
            comboBoxHall.Items.Clear();

            //utk masukkan semua hall dlm comboboxHall
            SqlDataAdapter sda2 = new SqlDataAdapter("select * from hallTable", sqlcon);
            DataTable dt2 = new DataTable();
            sda2.Fill(dt2);

            foreach (DataRow dr2 in dt2.Rows)
            {
                hallName = dr2["hallName"].ToString();
                comboBoxHall.Items.Add(hallName);
            }

            //utk update comboboxHall jika hall yg sama telah ada utk movie, time, hari sama
            SqlDataAdapter sda = new SqlDataAdapter("select hallName from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId where scheduleTime = '" + scheduleTime + "' and scheduleDate = '" + scheduleDate.ToString("yyyy-MM-dd") + "'", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            foreach (DataRow dr in dt.Rows)
            {
                hallName = dr["hallName"].ToString();
                comboBoxHall.Items.Remove(hallName);
            }

            comboBoxHall.Text = "";
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            DialogResult yesno = MessageBox.Show("Are you sure to delete selected schedule?", "Delete confirmation", MessageBoxButtons.YesNo);

            if(yesno == DialogResult.Yes)
            {
                string delete = "Delete from scheduleTable where scheduleId = '" + scheduleId + "'";

                sqlcon.Open();
                SqlCommand cmd = new SqlCommand(delete, sqlcon);
                cmd.ExecuteNonQuery();
                sqlcon.Close();
            }
            else
            {

            }

            refresh();
        }

        private void refresh()
        {
            SqlDataAdapter sda3 = new SqlDataAdapter("select scheduleId [ID], movieName [Movie], hallName [Hall], scheduleDate [Date], scheduleTime [Time], schedulePrice [Price] from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId inner join movieTable on movieTable.movieId = scheduleTable.movieId order by scheduleDate", sqlcon);
            DataTable dt3 = new DataTable();
            sda3.Fill(dt3);

            dataGridView1.DataSource = dt3;
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                dataGridView1.CurrentRow.Selected = true;

                scheduleId = int.Parse(dataGridView1.Rows[e.RowIndex].Cells["ID"].FormattedValue.ToString());
            }
        }

        private void comboBoxMovieName_SelectedIndexChanged(object sender, EventArgs e)
        {
            scheduleMovieName1 = comboBoxMovieName.SelectedItem.ToString();
            Gather(scheduleMovieName1, scheduleDate, scheduleTime, scheduleHallName, schedulePrice);
            checkHall();
        }

        private void comboBoxHall_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
