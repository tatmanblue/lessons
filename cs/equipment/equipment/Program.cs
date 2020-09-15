using System;

namespace equipment
{
    class Program
    {
        static void Main(string[] args)
        {
            EquipmentStat attack = new EquipmentStat() { Name = "attack", Value = 19 };
            EquipmentStat defense = new EquipmentStat() { Name = "defense", Value = 4 };

            Equipable sword = new Equipable() { Placement = EquipmentPlacement.LeftHand };
            sword.Stats.Add(attack);
            sword.Stats.Add(defense);

            EquipmentWorn worn = new EquipmentWorn();
            worn.Items.Add(sword);

            Console.WriteLine($"{worn.SumOfStats("attack")}");
            Console.ReadKey();
        }
    }
}
