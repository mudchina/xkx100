//Room: hutouyan.c 虎头岩
//Date: Sep 22 1997
inherit ROOM;
void create()
{
      set("short","虎头岩");
      set("long",@LONG
一块巨大的岩石看上去好象一个虎头正张大了血盆大口咆哮，虎身
隐藏在草木丛中。
LONG);
      set("objects", ([
          __DIR__"npc/laohu" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wulaofeng",
          "southup"  : __DIR__"chaotiangong",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
	set("coor/x", -2030);
	set("coor/y", -980);
	set("coor/z", 140);
	setup();
      replace_program(ROOM);
}
