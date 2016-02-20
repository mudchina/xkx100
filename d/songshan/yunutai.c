// Room: /d/songshan/yunutai.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "玉女台");
	set("long", @LONG
这理是嵩山东南的玉女台。玉女台下的石淙洞，就是“石淙会饮”
(jing)之处。两岸石壁高耸，险峻如削，怪古嶙峋多姿，大小别致。涧
中有巨石，两岸多洞穴，水声石响，淙淙有声，故名“石淙”。
LONG );
	set("item_desc", ([
		"jing" : "
    石上青苔满布，润水清澈见底，上空莺歌燕舞，水中群鱼战游。碧
水潭中有个大石头，独出水面，平整如案。登上石顶眺望，周围是水，
四面环山，红日映染河水，微风徐徐扑面，山青水秀，鸟语花香，大有
人在书中之感。明初诗人郑大原《游石淙》诗云：
                  驱车未到已闻声，隐耳轻雷更不惊。
                  石淙参差人坐立，潭并莹激鉴真平。
                  徐风入沼回环转，曲水浮移委宛行。
                  敬借付君舟棹用，不教河汉隔盈盈。
    古时称石淙润为“水营山阵”、“天中胜景”，每逢九月九日重阳
佳节，人们携带酒菜，登水中石上，猜拳行令，饮览胜景。唐代女皇武
则天，多次到石淙寻欢作乐。久视元年五月武后游览中岳时，会在此台
上，笙笛歌舞，大宴群臣，提笔赋诗，摩崖碑刻。据此，史称“石淙会
饮”。
    唐武则天《石淙》诗云：
                  三山十洞光玄篆，玉峤金恋镇紫微。
                  均露均霜标胜壤，交风交雨列皇战。
                  万仞高崖藏日色，千寻幽润浴云衣。
                  且驻欢筵赏仁智，稠鞍薄晚杂尘飞。
",
	]));
	set("exits", ([
		"northwest" : __DIR__"shandao1",
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
