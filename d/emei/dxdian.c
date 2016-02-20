//Room: dxdian.c 大雄殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","大雄殿");
      set("long",@LONG
这里是报国寺大雄殿。报国寺是峨嵋山最大寺院之一。大雄殿内供着金光
灿灿的佛像，气宇轩昂。
LONG);
      set("objects", ([
               __DIR__+"npc/guest": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"bgschanfang",
          "out"      : __DIR__"bgs",
          "north"    : __DIR__"cangjinglou",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6020);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "峨嵋派")) && (dir == "west"))
      return notify_fail("保国寺禅房只接待峨嵋弟子，你要是诚心礼佛，在此多进几注香吧。\n");
    else  return 1;
}