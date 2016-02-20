// Room: /d/wizard/wizard_room.c
// Last modified by winder 2002/10/18

inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是「侠客行一百」巫师的休息所在，刚粉刷过的四周墙壁上
光秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫
师留言簿(board)。
LONG );

	set("exits", ([ /* sizeof() == 1 */
		"up"    : __DIR__"meeting_room",
	 	"down"  : __DIR__"guest_room",
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("coor/x",-1);
	set("coor/y",1);
	set("coor/z",10);
	setup();

	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
