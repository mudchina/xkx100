//Room: xiaoshulin4.c 小树林
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_chuang();
string look_paizi();

void create()
{
      set("short","小树林");
      set("long",@LONG
这是峨嵋山金顶华藏庵外的一片小树林。北边是峨嵋派女弟子们的寝宫的
窗户，窗下好像蹲着一个人。
LONG);
      set("objects", ([
           __DIR__"npc/xiaosong" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northwest" : __DIR__"xiaoshulin3", 
          "north"     : __DIR__"qinggong", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1210);
	set("coor/z", 180);
	setup();
}
int valid_leave(object me, string dir)
{
      mapping myfam;
      myfam = (mapping)me->query("family");
      if ((!myfam || (myfam["family_name"] != "峨嵋派")) && (dir == "north"))
          return notify_fail("你好大的胆子，想闯峨嵋女弟子的寝宫？\n");
      else  return 1;
}