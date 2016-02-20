// Room: /wuliang/xiaowu.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "囚室");
	set("long", @LONG
这是一间木头小屋。房中陈设简陋，窗上铁条纵列，看来竟然便
是无量剑关人的所在，只是开间宽敞，倒无局促之感，
LONG );
        set("no_sleep_room",1);
	set("exits", ([
		"west"       : __DIR__"huayuan",
	]));
	set("coor/x", -70970);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}