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
    public partial class Form2 : Form
    {
        string movieName;
        string scheduleTime;
        int scheduleId;
        decimal schedulePrice;
        Action<string> displayMessage = str => MessageBox.Show(str);
        decimal totalPrice;
        Hall hall = new Hall();
        decimal hallCharge;
        string hallName;
        
        public Form2()
        {
            InitializeComponent();
        }

        SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");
        private void Form2_Load(object sender, EventArgs e)
        {
            SqlDataAdapter sda = new SqlDataAdapter("select scheduleTable.movieId, movieName [Movie]  from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId inner join movieTable on movieTable.movieId = scheduleTable.movieId where scheduleDate = cast(GETDATE() as date) group by scheduleTable.movieId, movieTable.movieName", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            comboBoxMovie.Items.Clear();

            foreach(DataRow dr in dt.Rows)
            {
                comboBoxMovie.Items.Add(dr["Movie"].ToString());
            }
        }

        private void comboBoxMovie_SelectedIndexChanged(object sender, EventArgs e)
        {
            movieName = comboBoxMovie.SelectedItem.ToString();

            SqlDataAdapter sda = new SqlDataAdapter("select scheduleTime [Time] from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId inner join movieTable on movieTable.movieId = scheduleTable.movieId where movieName = '"+movieName+ "' AND scheduleDate = cast(GETDATE() as date)  group by scheduleTime", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            comboBoxTime.Items.Clear();

            foreach(DataRow dr in dt.Rows)
            {
                comboBoxTime.Items.Add(dr["Time"].ToString());
            }
        }

        private void comboBoxTime_SelectedIndexChanged(object sender, EventArgs e)
        {
            scheduleTime = comboBoxTime.SelectedItem.ToString();

            SqlDataAdapter sda = new SqlDataAdapter("select hallName [Hall] from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId inner join movieTable on movieTable.movieId = scheduleTable.movieId where scheduleTime = '"+scheduleTime+"' and movieName = '"+movieName+ "' and scheduleDate = cast(GETDATE() as date)", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            comboBoxHall.Items.Clear();

            foreach(DataRow dr in dt.Rows)
            {
                comboBoxHall.Items.Add(dr["Hall"].ToString());
            }
        }

        private void comboBoxHall_SelectedIndexChanged(object sender, EventArgs e)
        {
            panel1.Enabled = true;

            hallName = comboBoxHall.SelectedItem.ToString();

            resetSeat();

            SqlDataAdapter sda = new SqlDataAdapter("select scheduleId [Schedule ID], hallType [Hall Type] from scheduleTable inner join hallTable on hallTable.hallId = scheduleTable.hallId inner join movieTable on movieTable.movieId = scheduleTable.movieId where scheduleTime = '" + scheduleTime+"' and movieName = '"+movieName+ "' and hallName = '"+hallName+"' and scheduleDate = cast(getdate() as date)", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            foreach(DataRow dr in dt.Rows)
            {
                scheduleId = int.Parse(dr["Schedule ID"].ToString());
                hall.HallType = dr["Hall Type"].ToString();
            }

            if(hall.HallTypeCharge)
            {
                MessageBox.Show("An extra RM4 will be charge for each seat.");
            }
            else
            {

            }

            hallCharge = hall.HallPrice;

            //nak tentukan seat yg dh di pick
            SqlDataAdapter sda2 = new SqlDataAdapter("select seatNumber [Seat No] from ticketTable where scheduleId = '" + scheduleId + "'", sqlcon);
            DataTable dt2 = new DataTable();
            sda2.Fill(dt2);

            foreach(DataRow dr2 in dt2.Rows)
            {
                pickedSeat(int.Parse(dr2["Seat No"].ToString()));
            }
        }

        private void buttonProceed_Click(object sender, EventArgs e)
        {
            string seat = "";

            foreach(string seat1 in listBox1.Items)
            {
                seat += " '"+seat1+"' ";
            }

            DialogResult yesno = MessageBox.Show("Proceed to pay for " + seat + "?", "To pay", MessageBoxButtons.YesNo);

            if (totalPrice == 0)
            {
                MessageBox.Show("Please select a seat.");
            }
            else
            {
                if (yesno == DialogResult.Yes)
                {
                    for (int i = 0; i < listBox1.Items.Count; i++)
                    {
                        string insert = "insert into ticketTable (scheduleId, seatNumber, ticketPrice) values ('" + scheduleId + "', '" + listBox1.Items[i].ToString() + "', '" + schedulePrice + "')";

                        sqlcon.Open();
                        SqlCommand cmd = new SqlCommand(insert, sqlcon);
                        cmd.ExecuteNonQuery();
                        sqlcon.Close();
                    }

                    displayMessage("Transaction success.");

                    listBox1.Items.Clear();
                    labelTotal.Text = "";
                }
                else if (yesno == DialogResult.No)
                {

                }
            }
        }

        private void pickedSeat(int seatNumber)
        {
            if(seatNumber == 1)
            {
                button1.BackColor = Color.Red;
                button1.Enabled = false;
            }
            if (seatNumber == 2)
            {
                button2.BackColor = Color.Red;
                button2.Enabled = false;
            }
            if (seatNumber == 3)
            {
                button3.BackColor = Color.Red;
                button3.Enabled = false;
            }
            if (seatNumber == 4)
            {
                button4.BackColor = Color.Red;
                button4.Enabled = false;
            }
            if (seatNumber == 5)
            {
                button5.BackColor = Color.Red;
                button5.Enabled = false;
            }
            if (seatNumber == 6)
            {
                button6.BackColor = Color.Red;
                button6.Enabled = false;
            }
            if (seatNumber == 7)
            {
                button7.BackColor = Color.Red;
                button7.Enabled = false;
            }
            if (seatNumber == 8)
            {
                button8.BackColor = Color.Red;
                button8.Enabled = false;
            }
            if (seatNumber == 9)
            {
                button9.BackColor = Color.Red;
                button9.Enabled = false;
            }
            if (seatNumber == 10)
            {
                button10.BackColor = Color.Red;
                button10.Enabled = false;
            }
            if (seatNumber == 11)
            {
                button11.BackColor = Color.Red;
                button11.Enabled = false;
            }
            if (seatNumber == 12)
            {
                button12.BackColor = Color.Red;
                button12.Enabled = false;
            }
            if (seatNumber == 13)
            {
                button13.BackColor = Color.Red;
                button13.Enabled = false;
            }
            if (seatNumber == 14)
            {
                button14.BackColor = Color.Red;
                button14.Enabled = false;
            }
            if (seatNumber == 15)
            {
                button15.BackColor = Color.Red;
                button15.Enabled = false;
            }
            if (seatNumber == 16)
            {
                button16.BackColor = Color.Red;
                button16.Enabled = false;
            }
            if (seatNumber == 17)
            {
                button17.BackColor = Color.Red;
                button17.Enabled = false;
            }
            if (seatNumber == 18)
            {
                button18.BackColor = Color.Red;
                button18.Enabled = false;
            }
            if (seatNumber == 19)
            {
                button19.BackColor = Color.Red;
                button19.Enabled = false;
            }
            if (seatNumber == 20)
            {
                button20.BackColor = Color.Red;
                button20.Enabled = false;
            }
            if (seatNumber == 21)
            {
                button21.BackColor = Color.Red;
                button21.Enabled = false;
            }
            if (seatNumber == 22)
            {
                button22.BackColor = Color.Red;
                button22.Enabled = false;
            }
            if (seatNumber == 23)
            {
                button23.BackColor = Color.Red;
                button23.Enabled = false;
            }
            if (seatNumber == 24)
            {
                button24.BackColor = Color.Red;
                button24.Enabled = false;
            }
            if (seatNumber == 25)
            {
                button25.BackColor = Color.Red;
                button25.Enabled = false;
            }
            if (seatNumber == 26)
            {
                button26.BackColor = Color.Red;
                button26.Enabled = false;
            }
            if (seatNumber == 27)
            {
                button27.BackColor = Color.Red;
                button27.Enabled = false;
            }
            if (seatNumber == 28)
            {
                button28.BackColor = Color.Red;
                button28.Enabled = false;
            }
            if (seatNumber == 29)
            {
                button29.BackColor = Color.Red;
                button29.Enabled = false;
            }
            if (seatNumber == 30)
            {
                button30.BackColor = Color.Red;
                button30.Enabled = false;
            }
            if (seatNumber == 31)
            {
                button31.BackColor = Color.Red;
                button31.Enabled = false;
            }
            if (seatNumber == 32)
            {
                button32.BackColor = Color.Red;
                button32.Enabled = false;
            }
            if (seatNumber == 33)
            {
                button33.BackColor = Color.Red;
                button33.Enabled = false;
            }
            if (seatNumber == 34)
            {
                button34.BackColor = Color.Red;
                button34.Enabled = false;
            }
            if (seatNumber == 35)
            {
                button35.BackColor = Color.Red;
                button35.Enabled = false;
            }
            if (seatNumber == 36)
            {
                button36.BackColor = Color.Red;
                button36.Enabled = false;
            }
            if (seatNumber == 37)
            {
                button37.BackColor = Color.Red;
                button37.Enabled = false;
            }
            if (seatNumber == 38)
            {
                button38.BackColor = Color.Red;
                button38.Enabled = false;
            }
            if (seatNumber == 39)
            {
                button39.BackColor = Color.Red;
                button39.Enabled = false;
            }
        }

        private void resetSeat()
        {
            button1.BackColor = Color.Transparent;
            button1.Enabled = true;
            button2.BackColor = Color.Transparent;
            button2.Enabled = true;
            button3.BackColor = Color.Transparent;
            button3.Enabled = true;
            button4.BackColor = Color.Transparent;
            button4.Enabled = true;
            button5.BackColor = Color.Transparent;
            button5.Enabled = true;
            button6.BackColor = Color.Transparent;
            button6.Enabled = true;
            button7.BackColor = Color.Transparent;
            button7.Enabled = true;
            button8.BackColor = Color.Transparent;
            button8.Enabled = true;
            button9.BackColor = Color.Transparent;
            button9.Enabled = true;
            button10.BackColor = Color.Transparent;
            button10.Enabled = true;
            button11.BackColor = Color.Transparent;
            button11.Enabled = true;
            button12.BackColor = Color.Transparent;
            button12.Enabled = true;
            button13.BackColor = Color.Transparent;
            button13.Enabled = true;
            button14.BackColor = Color.Transparent;
            button14.Enabled = true;
            button15.BackColor = Color.Transparent;
            button15.Enabled = true;
            button16.BackColor = Color.Transparent;
            button16.Enabled = true;
            button17.BackColor = Color.Transparent;
            button17.Enabled = true;
            button18.BackColor = Color.Transparent;
            button18.Enabled = true;
            button19.BackColor = Color.Transparent;
            button19.Enabled = true;
            button20.BackColor = Color.Transparent;
            button20.Enabled = true;
            button21.BackColor = Color.Transparent;
            button21.Enabled = true;
            button22.BackColor = Color.Transparent;
            button22.Enabled = true;
            button23.BackColor = Color.Transparent;
            button23.Enabled = true;
            button24.BackColor = Color.Transparent;
            button24.Enabled = true;
            button25.BackColor = Color.Transparent;
            button25.Enabled = true;
            button26.BackColor = Color.Transparent;
            button26.Enabled = true;
            button27.BackColor = Color.Transparent;
            button27.Enabled = true;
            button28.BackColor = Color.Transparent;
            button28.Enabled = true;
            button29.BackColor = Color.Transparent;
            button29.Enabled = true;
            button30.BackColor = Color.Transparent;
            button30.Enabled = true;
            button31.BackColor = Color.Transparent;
            button31.Enabled = true;
            button32.BackColor = Color.Transparent;
            button32.Enabled = true;
            button33.BackColor = Color.Transparent;
            button33.Enabled = true;
            button34.BackColor = Color.Transparent;
            button34.Enabled = true;
            button35.BackColor = Color.Transparent;
            button35.Enabled = true;
            button36.BackColor = Color.Transparent;
            button36.Enabled = true;
            button37.BackColor = Color.Transparent;
            button37.Enabled = true;
            button38.BackColor = Color.Transparent;
            button38.Enabled = true;
            button39.BackColor = Color.Transparent;
            button39.Enabled = true;
        }

        
        public delegate decimal Total(decimal x, decimal y);
        Total total = (x, y) => x + y;

        public Func<decimal,decimal, decimal> TotalPrice =(x,y)=> x * y;
        
        private void buttonAllSeat_Click(object sender, EventArgs e)
        {
            SqlDataAdapter sda = new SqlDataAdapter("select schedulePrice [Price] from scheduleTable where scheduleId = '" + scheduleId + "'", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            foreach(DataRow dr in dt.Rows)
            {
                schedulePrice = decimal.Parse(dr["Price"].ToString());
            }

            Button seat = sender as Button;

            if (seat.BackColor == Color.Green)
            {
                seat.BackColor = Color.Transparent;
                listBox1.Items.Remove(seat.Text);
            }
            else
            {
                seat.BackColor = Color.Green;
                listBox1.Items.Add(seat.Text);
            }
            
            totalPrice = TotalPrice(total(schedulePrice , hallCharge), listBox1.Items.Count);
            labelTotal.Text = totalPrice.ToString();
        }

   
    }
}
