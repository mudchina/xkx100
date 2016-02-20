//Room: cangjingge.c 藏经阁
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","藏经阁");
      set("long",@LONG
小阁楼上便是峨嵋派的藏经阁了。这里都是密密麻麻，高及顶棚的书架。
窗口下有一张大桌子，桌上放了几本佛经。有个小师太正在向静道师太借书。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/dao" : 1,
           __DIR__"obj/fojing1"+random(2) : 1,
           __DIR__"obj/fojing2"+random(2) : 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
          "down"  : __DIR__"chuwujian", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1200);
	set("coor/z", 200);
	setup();
}
int valid_leave(object me, string dir)
{
     if ((dir == "south") && ( present("shu", me))
          && objectp(present("jingdao", environment(me))))
     {
         return notify_fail
                ("静道师太见你想把经书拿走，上前轻声说道：本阁经书不外借。\n");
     }
     return ::valid_leave(me, dir);
}