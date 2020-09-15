using System;
using System.Collections.Generic;
using System.Text;

namespace equipment
{
    public class Equipable
    {
        public EquipmentPlacement Placement { get; set; }
        public int Value { get; set; }
        public List<EquipmentStat> Stats { get; set; }

        public Equipable()
        {
            Stats = new List<EquipmentStat>();
        }
    }
}
