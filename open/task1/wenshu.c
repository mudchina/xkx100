// wenshu.c
#include <ansi.h>
inherit ITEM;
string target;

void create()
{
	set_name(WHT "海捕文书" NOR, ({ "wenshu", "wen",}));
	set("weight", 100);
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "张");
		set("long", WHT"这是一张海捕文书，上面有一个画像，底下有一行小字，你可以仔细看看。\n" NOR);
		set("value", 0);
		set("no_get", 1);
		set("no_drop", 1);
	}
	setup();
}
 
 
#include "wenshu.h"
