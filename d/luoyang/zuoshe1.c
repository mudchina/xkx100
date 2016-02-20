//  Room:  /d/luoyang/zuoshe1.c
#include <ansi.h>
inherit  ROOM;

void  create  ()
{
	set("short",  "左舍");
	set("long",  @LONG
走进小舍，见桌椅几榻，无一而非竹制，一只竹枝撑起竹窗，凉风
灌入，如仙风入堂。西边是内进，一层细竹窗帘后，又障了一层轻纱，
你只隐隐约约的见到有个人影，五官面貌却一点也无法见到。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southeast"  :  __DIR__"lvzhuxiaoyuan",
		"west"       :  __DIR__"zuoshe2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -381);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}