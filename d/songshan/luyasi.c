// Room: /d/songshan/luyasi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "卢崖寺");
	set("long", @LONG
忽听水声如雷，悬练峰下一座高大的石崖峭壁上，两条玉龙直挂下
来，双瀑并泄，屈曲回旋，飞跃奔逸，水花映日，淡淡冕生。唐玄宗年
间，有一个被封为谏仪大夫的卢鸿乙，不原做官，来此隐居，广招天下
才子，在此讲学，此崖遂称为“卢崖”，鸿乙隐居处称为“早堂”。鸿
乙仙游之后，玄宗改“草堂”为“卢崖寺”。嵩山八景的“卢崖瀑布”
(jing)便在此间。
    瀑布斜过就是胜观峰。瀑布之侧有路可上。
LONG );
	set("item_desc", ([
		"jing" : "
    卢崖寺北峡谷内，有一股泉水，终年不断，平时泉水泻崖下，好似
千丈珠廉掣挂长空。澎湃之声，如虎豹怒吼，如雷声轰鸣。太阳直射上
面，奇光异彩，灿烂夺目，瞬息万变，气象万千。水珠积流，形成水潭，
潭上独出一个黛色圆石，明朝袁宏道在上面刻有“墨浪石”三个大字。
水流其上，好似墨浪。人称此景为“卢崖瀑布墨浪流”，亦称“珍珠倒
卷廉”。
    明高出《卢崖瀑布》诗云：
                太室东来第几峰，孤崖侧削半芙蓉。
                为看飞瀑三千尺，直透春云一万重。
",
	]));
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"        : __DIR__"tieliang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 810);
	set("coor/z", 30);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")    
	{
		return notify_fail("你使劲儿一蹦，离瀑布顶还有数丈远就掉了下来，摔的鼻青脸肿。\n");
	}
	if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")    
	{
		return notify_fail("你奋力一跃，却离瀑布顶还有一丈多远，看来是白费力气。\n");
	}
	if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")    
	{
		return notify_fail("你纵身而起，离瀑布顶只差一点点了，再加把劲。\n");
	}
	return ::valid_leave(me, dir);
}
