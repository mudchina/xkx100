//Room: mozhenjing.c 磨针井
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","磨针井");
      set("long",@LONG
相传当年真武进山修炼，日久思归，偶遇一老妇持铁杵研磨。问磨
杵为何？答以磨针。又问铁杵岂能磨针？答云功到自然成。真武由此醒
悟，终于修炼成仙。后人因建磨针井道观以为纪念。殿前立大铁杵一根，
殿旁有老母亭，亭正中有井(jing)。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"shanlu1",
      ]));
      set("item_desc",([ 
          "jing"     : "井沿古朴，水色悠蓝，可以装瓶饮用。\n",
      ]));
      set("resource/water", 1);
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -850);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}
