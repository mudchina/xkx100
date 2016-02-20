//Room: slxl2.c 松林小路
//Date: Sep 22 1997

inherit ROOM;

string look_shibei();

void create()
{
      set("short","松林小路");
      set("long",@LONG
这是山脚松林中的小路，两边长满参天的红松树，只能看见一线天
空。路旁有道士在奋力砍树。东边可回大道。
    路边有个石碑(shibei)，很多游客在围那里。原来西边上去就是名
震天下的解剑岩了，
LONG);
      set("outdoors", "wudang");
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "westup" : __DIR__"jiejianyan",
          "east"   : __DIR__"slxl1",
          "south"  : __DIR__"songlin1",
          "north"  : __DIR__"songlin2",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}

string look_shibei()
{
        return
        "※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "※※※※　        　　　　　　　　　　　　※※※※\n"
        "※※※※　        　武当派通告    　　　　※※※※\n"
        "※※※※　                            　　※※※※\n"
        "※※※※　    往前就是武当山解剑岩。所有　※※※※\n"
        "※※※※　外来人客请自觉解剑。邪魔外道到　※※※※\n"
        "※※※※　此止步。                　　　　※※※※\n"
        "※※※※　　　　　                　　　　※※※※\n"
        "※※※※※※※※※※※※※※※※※※※※※※※※※\n";
}
