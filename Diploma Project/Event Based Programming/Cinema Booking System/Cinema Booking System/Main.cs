using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cinema_Booking_System
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        public Main(string role)
        {
            InitializeComponent();

            if(role == "Staff")
            {
                moviesToolStripMenuItem.Visible = false;
                scheduleToolStripMenuItem.Visible = false;
                allBookingToolStripMenuItem.Visible = false;
            }
        }

        private void scheduleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 schedule = new Form1();
            schedule.MdiParent = this;
            schedule.Dock = DockStyle.Fill;
            schedule.Show();
        }

        private void bookingToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Form2 ticket = new Form2();
            ticket.MdiParent = this;
            ticket.Dock = DockStyle.Fill;
            ticket.Show();
        }

        private void allBookingToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form4 allBooking = new Form4();
            allBooking.MdiParent = this;
            allBooking.Dock = DockStyle.Fill;
            allBooking.Show();
        }

        private void moviesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 addMovie = new Form3();
            addMovie.MdiParent = this;
            addMovie.Dock = DockStyle.Fill;
            addMovie.Show();
        }

       
    }
}
