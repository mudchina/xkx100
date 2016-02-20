//Room: bgsgate.c 报国寺山门
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_gate();

void create()
{
      set("short","山门");
      set("long",@LONG
报国寺为峨嵋出入之门户。山门(gate)上有一块大匾。寺外苍楠环卫，翠
柏掩映。由此一路向西上开始登峨嵋山，北面下山是一条弯弯的石阶路。
LONG);
      set("outdoors", "emei");
      set("item_desc", ([
          "gate" : (: look_gate :),
      ]));
      set("objects", ([
               __DIR__+"npc/guest": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"qsjie2",
          "west"      : __DIR__"bgs",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6010);
	set("coor/y", -1030);
	set("coor/z", 10);
	setup();
}
string look_gate()
{
      return
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌　　　报　　国　　寺　　　≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n";
}