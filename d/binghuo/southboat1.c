// Room: /binghuo/southboat1.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "木筏");
	set("long", @LONG
此木筏是岛上参天古木扎就，竖立主桅副桅，这些木材因生于寒
冰之地，木质致密，硬如铁石。帆布和帆索都用树筋兽皮来编织、搓
结。筏上水腌肉，存贮清水的皮袋皆已具备。只欠......
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"haitan",
	]));
	setup();
}

void init()
{
	object ob = this_player();
	mapping fam;
	if ((strsrch(NATURE_D->game_time(), "一月") >= 0) ||
	   (strsrch(NATURE_D->game_time(), "二月") >= 0))
	{
		call_out("south1", 3, ob);
	}
	else
	{
		message_vision(HIR"\n现在北风未起，你恐怕回不去了！\n"NOR, ob);
	}
}

void south1( object ob )
{
	message_vision( BLU
"\n这时海流带动木排，缓缓飘开，$N眼见冰火岛慢慢模糊，渐渐
的小了下去。隔了良久良久，终于再也瞧不见了。\n\n" NOR, ob);
	ob ->move(__DIR__"southboat2") ;
	tell_object(ob, BLU 
"\n一路刮的是北风，带着木筏直向南行。在这茫茫大海之上，自也认不
出方向，但见每日太阳从左首升起，从右首落下，每晚北极星在筏后
闪烁，而木筏又是不停的移动，你便知离中原日近一日。\n" NOR ) ;
	call_out("south2", 10, ob);
}
void south2( object ob )
{
	tell_object(ob , BLU
"\n终于到港了，满身疲倦的你脚踏实地仍有虚浮的感觉。\n\n" NOR) ;
	ob->move ("/d/beijing/haigang");
}

