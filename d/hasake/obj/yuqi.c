#include <ansi.h>

inherit ITEM;

void create()
{
         switch(random(13)) {
        case 0 : set_name(GRN"玉人头饰"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 1 : set_name(HIY"兽面纹玉琮"NOR, ({"yu pei", "yu", "pei"})); break;
        case 2 : set_name(HIW"三叉形玉器"NOR, ({"yu pei", "yu", "pei"})); break;
        case 3 : set_name(MAG"玉龙"NOR, ({"yu pei", "yu", "pei"})); break;
        case 4 : set_name(YEL"猪龙形玉佩饰"NOR, ({"yu pei", "yu", "pei"})); break;
        case 5 : set_name(WHT"玉龟"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 6 : set_name(WHT"兔形玉佩"NOR, ({"yu pei", "yu", "pei"})); break;
        case 7 : set_name(YEL"虎形玉佩"NOR, ({"yu pei", "yu", "pei"})); break;
        case 8 : set_name(GRN"蛙形绿松石佩"NOR, ({"yu pei", "yu", "pei"})); break;
        case 9 : set_name(HIY"跪式玉人"NOR, ({"yu pei", "yu", "pei"})); break;
        case 10 : set_name(CYN"拱手玉人"NOR, ({"yu pei", "yu", "pei"})); break;
        case 11 : set_name(CYN"玉虎"NOR, ({"yu pei", "yu", "pei"})); break;
        case 12 : set_name(MAG"玉凤"NOR, ({"yu pei", "yu", "pei"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "块");
                set("weight", 1000);
		set("long", "这是东汉玉石饰品中的一个，出自陕西，山东，河南一带。\n");
		set("material", "stone");
		}
	setup();
}