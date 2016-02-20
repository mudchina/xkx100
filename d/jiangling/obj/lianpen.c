//Edited by fandog, 02/15/2000

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("脸盆", ({"lian pen", "pen"}));
	set("unit", "只");
	set("no_get", 1);

	set("long", "这是一只普通之极的脸盘，盆中装满了水。\n");
	setup();
}
