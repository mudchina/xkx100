#include <ansi.h>

inherit ITEM;

void create()
{
         switch(random(7)) {
        case 0 : set_name("牛文明墓画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 1 : set_name("车骑过桥画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 2 : set_name("狩猎画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 3 : set_name("桥头交战画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 4 : set_name("斗兽画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 5 : set_name("两桃杀三士画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 6 : set_name("比武画像石", ({ "xiang shi", "shi", "stone"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "块");
                set("weight", 1000);
		set("long", "这是东汉石雕像中的一个，出自陕西，山东，河南一带。\n");
		set("material", "stone");
		}
	setup();
}