using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cinema_Booking_System
{
    class Hall
    {
        private string hallName;
        private decimal hallPrice;
        private string hallType;
        private bool hallTypeCharge;

        public string HallName
        {
            get => hallName;
            set => hallName = value;
        }

        public string HallType
        {
            get => hallType;
            set
            {
                if (value == "Premium")
                {
                    hallPrice = 4.00m;
                    hallTypeCharge = true;
                }
                if (value == "Regular")
                {
                    hallPrice = 0.00m;
                    hallTypeCharge = false;
                }
            }
        }

        public decimal HallPrice
        {
            get => hallPrice;
        }

        public bool HallTypeCharge
        {
            get => hallTypeCharge;
        }
    }
}
