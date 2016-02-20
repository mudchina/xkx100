// Room: /d/wuxi/huishanquan.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "天下第二泉");
	set("long", @LONG
眼前已经来到惠山山脚，只见青松蔽日，耳竹林哨响。上山石阶
之旁，有一圆一方两池，圆池在上，方池在下。池西头雕有螭首，造
型古朴，泉水(quan)从龙口出。向北即可上得惠山。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"road14",
		"northup"  : __DIR__"road15",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));
	set("item_desc", ([
		"quan" : "眼前一泓清泉清鉴肌骨，池底净石，清晰可见。\n",
	]));
	set("coor/x", 260);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}