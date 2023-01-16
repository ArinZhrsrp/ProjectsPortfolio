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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");
        private void Form4_Load(object sender, EventArgs e)
        {
            string display = "select  ticketTable.ticketId [Ticket], scheduleTable.scheduleDate [Date], scheduleTable.scheduleTime [Time], movieTable.movieName [Movie], hallTable.hallName [Hall], ticketTable.seatNumber [Seat], scheduleTable.schedulePrice [Price] " +
                "from ticketTable " +
                "left join scheduleTable on scheduleTable.scheduleId = ticketTable.scheduleId " +
                "left join hallTable on hallTable.hallId = scheduleTable.hallId " +
                "left join movieTable on movieTable.movieId = scheduleTable.movieId";

            SqlDataAdapter sda = new SqlDataAdapter(display, sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            dataGridView1.DataSource = dt;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 0)
            {
                List<DataGridViewRow> q = (from item in dataGridView1.Rows.Cast<DataGridViewRow>()
                                           orderby item.Cells[1].Value.ToString() descending
                                           select item).ToList<DataGridViewRow>();

                dataGridView1.DataSource = q.Select(x => x.DataBoundItem).ToList();

            }
            else if (comboBox1.SelectedIndex == 1)
            {
                List<DataGridViewRow> q = (from item in dataGridView1.Rows.Cast<DataGridViewRow>()
                                           orderby item.Cells[1].Value.ToString()
                                           select item).ToList<DataGridViewRow>();

                dataGridView1.DataSource = q.Select(x => x.DataBoundItem).ToList();
            }
            else if (comboBox1.SelectedIndex == 2)
            {
                List<DataGridViewRow> q = (from item in dataGridView1.Rows.Cast<DataGridViewRow>()
                                           orderby item.Cells[6].Value.ToString()
                                           select item).ToList<DataGridViewRow>();

                dataGridView1.DataSource = q.Select(x => x.DataBoundItem).ToList();
            }
            else if (comboBox1.SelectedIndex == 3)
            {
                List<DataGridViewRow> q = (from item in dataGridView1.Rows.Cast<DataGridViewRow>()
                                           orderby item.Cells[6].Value.ToString() descending
                                           select item).ToList<DataGridViewRow>();

                dataGridView1.DataSource = q.Select(x => x.DataBoundItem).ToList();
            }
        }
    }
}
