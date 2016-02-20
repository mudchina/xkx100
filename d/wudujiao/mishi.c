// Room: /d/wudujiao/mishi.c
// Last modified by ahda  Jul 17 2001
// Ln67 面壁五毒神功没加上限限制，暂时先限制在180~200

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是一座不大的石室，房间落满灰尘，好象有多年没人打扫似
的。室内只有一床一案，一缕阳光从洞顶的岩缝中射入，室内光线明
亮。墙边有一个青石床(bed)，与旁边石壁的色泽有很大不同。透过
斜射的阳光，你看到石床对面墙壁上似乎刻着一些文字和图形。一个
宽大的石案上摆着一个石匣(xia)。
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
        set("exits", ([
                "eastup" : __DIR__"shixi",
        ]));
        set("item_desc",([
         "wall":"\n       只见石壁上刻着“千蛛万毒”四个龙飞凤舞的大字。\n
       下面有三个盘膝而坐的人像，刻得栩栩如生，每个人姿势都不相同。\n
       旁边还有许多小字,你不妨照着练习(lianxi)一下。\n ",
         "墙壁":"\n       只见石壁上刻着“千蛛万毒”四个龙飞凤舞的大字。\n
       下面有三个盘膝而坐的人像，刻得栩栩如生，每个人姿势都不相同。\n
       旁边还有许多小字，你不妨照着练习(lianxi)一下。\n ",
         "bed":"\n一个普普通通的石床。\n ",
         "xia":"\n一只石匣，好象是和石案连在一起的，不知道敢不敢打开看看。\n ",
        ]));
        set("mishi_book",1);
        set("coor/x", -44960);
	set("coor/y", -81120);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_lianxi", "lianxi");
        add_action("do_jump", "jump");
        add_action("do_open", "open");
}

int do_lianxi(string arg)
{
        object weapon;
        object me=this_player();
        int forceskill=(int)me->query_skill("force", 1);
        int wuduskill=(int)me->query_skill("wudu-shengong", 1);
        int maxlevel, exp=(int)me->query("combat_exp");
        if( me->query("jing") < (int)(me->query("max_jing")/5))
            return notify_fail("你已经没有精力练习了！\n");
        if (!((string)me->query("family/family_name")=="五毒教")
            || !(int)me->query_temp("wudu_onbed"))
        {
        message_vision("$N盘膝而坐，照着壁上的图形练了几次，只觉得一阵口干舌燥。\n", me);
        }
        else
        {
        message_vision("$N照着壁上图形的姿势盘膝坐下，很快就静下心来。\n", me);
            if (exp*10 <= (wuduskill*wuduskill*wuduskill))
            {
                me->receive_damage("qi", 30);
                return notify_fail("但是你的经验不够，始终不能从图中领悟到什么。\n");
            }
            if (wuduskill > 179 & forceskill>150 & wuduskill < 200 )
            {
                me->improve_skill("wudu-shengong", 2*(int)(me->query("int")+me->query_skill("literate")));
                tell_object(me, "你似乎从中领悟出一些五毒神功方面的窍门。\n");
            }
            else
            {
                tell_object(me, "你的功夫太低了，还不能领会图形所载的练功法门。\n");
            }
        }
        me->receive_damage("jing", 20);
        return 1;
}
int do_jump(string arg)
{
        object me=this_player();
        if( !arg ||! (arg =="bed" || arg =="up" || arg =="down"))
            return 0;
        if( arg =="up"||arg=="bed"){
            if ((int)me->query_temp("wudu_onbed") )
                return notify_fail("你已经在床上了，再跳就碰到洞顶了。\n");
            me->set_temp("wudu_onbed",1);
            message_vision("$P轻轻一纵跳上了石床，坐了下来。\n", me);
            tell_object(me, "你只觉得一丝丝凉气从身下传来，顿绝精神一振。\n");
        }
        if( arg =="down"){
            if (!(int)me->query_temp("wudu_onbed") )
                return notify_fail("你已经在地下了，乱蹦乱跳成何体统？\n");
            me->delete_temp("wudu_onbed");
            message_vision("$P从石床上跳了下来。\n", me);
        }
        return 1;
}
int valid_leave (object me, string dir)
{
        if (me->query_temp("wudu_onbed"))
            return notify_fail("先下床再走，连走路也不会吗？\n");
        return 1;
}
int do_open(string arg)
{
        object me,ob;
        me=this_player();
        if( !arg || arg !="xia")
            return 0;
        if( query("mishi_book") < 1)
            return notify_fail("你打开石匣。但见里面空空如也。\n");
        add("mishi_book", -1);
        message_vision("$P打开石匣，从里面取出一束绢册。\n", me);
        ob = new("/clone/book/poisonbook3");
        ob->move(me);
        return 1;
}

