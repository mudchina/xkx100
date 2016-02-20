//Room: xixiangchi.c 洗象池
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_pool();

void create()
{
      set("short","洗象池");
      set("long",@LONG
洗象池原只是一亭，亭前有一个石砌的小池(pool)，池边不远就是危岩。
洗象池寓于一片冷杉林中，有若白云深处的仙山琼阁。若是云收雾敛、碧空万
里、月朗中天时，便觉万籁俱寂，清光无限，宛若身在天宫，彻体生凉。这正
是著名的「象池池夜」。由此向南上攀，便至雷洞坪，东下至莲花石。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"ztpo2",
          "southup"   : __DIR__"lingyunti",
      ]));
      set("item_desc", ([
          "pool" : (: look_pool :),
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1080);
	set("coor/z", 130);
	setup();
}
string look_pool()
{
    return
"这是一个石砌的六角小池，传说普贤乘象至此，必先在此池沐浴其象，而后才\n"
"升至金顶，故为「洗象池」。\n";
}