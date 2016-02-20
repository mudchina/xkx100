// Room: /d/wuxi/road14.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "西驿道");
	set("long", @LONG
这是一条宽阔的大驿道，由于离城市不远，路两边树林成片，林
荫间，凉风习习。驿道上一有马匹疾而过就飞起成片的灰尘。许久才
会散尽。路上的行人大多行色匆匆。向东可以远远地看见无锡城的城
头了。北面是著名的天下第二泉，惠山泉。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"road16",
		"east"   : __DIR__"kuaxiqiao",
		"north"  : __DIR__"huishanquan",
	]));
	set("coor/x", 260);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}