//Room: qingyinge.c 清音阁
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_shibei();

void create()
{
      set("short","清音阁");
      set("long",@LONG
这里是峨嵋山的清音阁。此阁位于牛心岭下，东有白龙江，西有黑龙江，
两江之水交汇于清音阁下。江上有拱桥两座，分跨黑龙白龙二江，这就是双飞
桥。两江合流处，有一数米高的黑褐色巨石傲然挺立，形似牛心，名之为「牛
心石」。桥边立有一石碑(shibei)。由此向西上，左行是黑龙江栈道，右路至
白龙洞，东去中峰寺。
LONG);
      set("outdoors", "emei");
      set("objects", ([
           CLASS_D("emei") + "/xian" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northwest" : __DIR__"bailongdong",
          "southwest" : __DIR__"heilong1",
          "southeast" : __DIR__"zhongfengsi",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6120);
	set("coor/y", -1030);
	set("coor/z", 80);
	setup();
}

string look_shibei()
{
        return


"石碑刻有一诗曰：\n\n"
"　　　　　　　杰 然 高 阁 出 清 音，\n\n"
"　　　　　　　仿 佛 仙 人 下 抚 琴。\n\n"
"　　　　　　　试 向 双 溪 一 倾 耳，\n\n"
"　　　　　　　无 情 两 水 漱 牛 心。\n\n"
"这就是“峨嵋十景诗”中专咏这“双桥清音”的诗。\n";
}