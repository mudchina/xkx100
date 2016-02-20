//Room: majiu.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","马厩");
      set("long",@LONG
这是关外的马厩，关外苦寒之地，颇乏新鲜草料。但东北大汉惯能
吃苦，马夫们会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干
乾净净，一直伺候到客人上路。马厩雪披下的木柱上歪歪地钉着一块破
木牌(paizi)。
LONG);
      set("outdoors", "guanwai");
      set("no_fight", "1");
      set("no_beg", "1");
      set("objects", ([
	    "/d/city/npc/zaohongma": 1,
	    "/d/city/npc/huangbiaoma": 1,
	    "/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      北京城:  ridebj


TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"jishi",
      ]));
      set("no_clean_up", 0);
	set("coor/x", 6030);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
