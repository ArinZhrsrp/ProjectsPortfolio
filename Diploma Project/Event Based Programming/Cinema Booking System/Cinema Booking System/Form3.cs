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
    public partial class Form3 : Form
    {
        string movieTitle;
        string genre;
        string language;
        string synopsis;
        string duration;

        SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");
        public Form3()
        {
            InitializeComponent();

        }

        private void Form3_Load(object sender, EventArgs e)
        {
            refresh();
        }

        //show messagebox
        Action<string> display = print => MessageBox.Show(print);
        //delegate
        public delegate void gather(string title, string masa, string sipnosis, string jenis, string bahasa);
        public delegate string Delete(string title, string genre, string language);

        private void btnDone_Click(object sender, EventArgs e)
        {
            try
            {
                gather gather = Gather;
                gather(txtMovieTitle.Text, txtDuration.Text, rtxtBoxSynopsis.Text, genre, language);

                string insert = "Insert into movieTable (movieName,movieSynopsis,movieDuration,movieLanguage,movieGenre) values ('" + movieTitle + "', '" + synopsis + "', '" + duration + "', '" + language + "', '" + genre + "')";

                sqlcon.Open();
                SqlCommand cmd = new SqlCommand(insert, sqlcon);
                cmd.ExecuteNonQuery();
                sqlcon.Close();

                display("Movie Added");
                clear();
                refresh();
            }
            catch
            {
                display("Movie Added");
            }

        }

        public void Gather(string title, string masa, string sipnosis, string jenis, string bahasa)
        {
            movieTitle = txtMovieTitle.Text;
            duration = txtDuration.Text;
            synopsis = rtxtBoxSynopsis.Text;

            if (cBoxGenre.SelectedIndex == 0)
                genre = "Action";
            else if (cBoxGenre.SelectedIndex == 1)
                genre = "Romance";
            else if (cBoxGenre.SelectedIndex == 2)
                genre = "Adventure";
            else
                genre = "Horror";

            if (cBoxLanguage.SelectedIndex == 0)
                language = "Myanmar";
            else if (cBoxLanguage.SelectedIndex == 1)
                language = "English";
            else if (cBoxLanguage.SelectedIndex == 2)
                language = "Melayu";
            else if (cBoxLanguage.SelectedIndex == 3)
                language = "Thailand";
            else
                language = "Indonesia";
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            clear();
        }

        private void clear() 
        {
            txtId.Text = $"ID";
            txtMovieTitle.Text = String.Empty;
            txtDuration.Text = String.Empty;
            cBoxGenre.SelectedIndex = -1;
            cBoxLanguage.SelectedIndex = -1;
            rtxtBoxSynopsis.Text = String.Empty;
        }
        

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string delete = del(label8.Text, label10.Text, label12.Text);
                
                sqlcon.Open();
                SqlCommand cmd = new SqlCommand(delete, sqlcon);
                cmd.ExecuteNonQuery();
                sqlcon.Close();

                display("Movie deleted.");
                clear();
                refresh();
            }
            catch
            {
                display("Movie deleted.");
            }
        }

        Delete del = (string title, string genre, string language) =>
        {
            string movieTitleDel = title;
            string genreDel = genre;
            string languageDel = language;
            string delete = $"Delete from movieTable where movieName='{movieTitleDel}' and movieGenre='{genreDel}' and movieLanguage='{languageDel}'";

            return delete;
        };

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int id;
            string title, duration, genre, language,synopsis;
            if (e.RowIndex >= 0)
            {
                dataGridView1.CurrentRow.Selected = true;

                id = int.Parse(dataGridView1.Rows[e.RowIndex].Cells["ID"].FormattedValue.ToString());
                title = dataGridView1.Rows[e.RowIndex].Cells["Title"].FormattedValue.ToString();
                genre = dataGridView1.Rows[e.RowIndex].Cells["Genre"].FormattedValue.ToString();
                language = dataGridView1.Rows[e.RowIndex].Cells["Language"].FormattedValue.ToString();
                duration = dataGridView1.Rows[e.RowIndex].Cells["Duration"].FormattedValue.ToString();
                synopsis = dataGridView1.Rows[e.RowIndex].Cells["Sysnopsis"].FormattedValue.ToString();
                txtId.Text = id.ToString();
                txtMovieTitle.Text = title;
                cBoxGenre.Text = genre;
                cBoxLanguage.Text = language;
                txtDuration.Text = duration;
                rtxtBoxSynopsis.Text = synopsis;
                label8.Text = title;
                label10.Text = genre;
                label12.Text = language;
                label13.Text = duration;

            }
        }

        private void refresh() 
        {
            SqlDataAdapter Sda = new SqlDataAdapter("select movieId [ID],  movieName [Title], movieGenre [Genre], movieLanguage [Language], movieDuration [Duration], movieSynopsis [Sysnopsis] from movieTable", sqlcon);
            DataTable dt = new DataTable();
            Sda.Fill(dt);

            dataGridView1.DataSource = dt;
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                sqlcon.Open();
                SqlCommand cmd = new SqlCommand("Update movieTable set movieName = @Title, movieGenre = @Genre, movieLanguage = @Language, movieDuration = @Duration, movieSynopsis = @Synopsis where movieId = @Id", sqlcon);
                cmd.Parameters.AddWithValue("@Id", int.Parse(txtId.Text));
                cmd.Parameters.AddWithValue("@Title", txtMovieTitle.Text);
                cmd.Parameters.AddWithValue("@Genre", cBoxGenre.Text);
                cmd.Parameters.AddWithValue("@Language", cBoxLanguage.Text);
                cmd.Parameters.AddWithValue("@Duration", txtDuration.Text);
                cmd.Parameters.AddWithValue("@Synopsis", rtxtBoxSynopsis.Text);
                cmd.ExecuteNonQuery();
                sqlcon.Close();

                display("Movie Updated");
                refresh();
            }
            catch
            {
                display("Movie Updated");
            }
        }

        private void txtDuration_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
