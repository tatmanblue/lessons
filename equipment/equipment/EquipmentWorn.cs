using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace equipment
{
    public class EquipmentWorn
    {
        public List<Equipable> Items { get; set; }

        public EquipmentWorn()
        {
            Items = new List<Equipable>();
        }

        /// <summary>
        /// this can be reduced down into a linq statement (not sure if unity C# supports
        /// all linq statements)
        /// </summary>
        /// <param name="statName"></param>
        /// <returns></returns>
        public int SumOfStats(string statName)
        {
            int sum = 0;
            foreach(Equipable item in Items)
            {
                foreach(EquipmentStat stat in item.Stats)
                {
                    if (stat.Name == statName)
                        sum += stat.Value;
                }
            }

            return sum;
        }
    }
}
