//Room: lengsl3.c 冷杉林
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","冷杉林");
      set("long",@LONG
这是一片遮天蔽日的冷杉林。数人也合抱不过来的冷杉树簇在一块，棵棵
枝繁叶茂，象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。看地上厚厚的枯
枝烂叶，显然游客很少踏足此处。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"bashisipan2",
          "northeast" : __DIR__"lengsl2",
          "southup"   : __DIR__"lengsl4",
      ]));
      set("objects",([ 
          __DIR__"npc/jumang" : 1,
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1110);
	set("coor/z", 160);
	setup();
      replace_program(ROOM);
}