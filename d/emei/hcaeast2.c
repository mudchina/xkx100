//Room: hcaeast2.c 华藏庵东廊
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","华藏庵东廊");
      set("long",@LONG
这里是峨嵋华藏庵东廊。走廊往南通往斋堂，北边通往广场。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"hcazhaitang", 
          "north" : __DIR__"hcaeast1", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1180);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}