//Room: wuyaling.c 乌鸦岭
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","乌鸦岭");
      set("long",@LONG
这是一狭长的脊岭，两侧悬削，一无所傍，但见白云朵朵，冉冉而
过，山风拂拂，阵阵袭来。数百只乌鸦正翱翔云际，黑白分明，蔚成奇
观。
LONG);
      set("objects", ([
                __DIR__"npc/wuya" : 5,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"langmeiyuan",
          "southup"  : __DIR__"sanlaofeng",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -950);
	set("coor/z", 110);
	setup();
      replace_program(ROOM);
}
