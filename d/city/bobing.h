
#include <ansi.h>
inherit ROOM;

int Maxperson=100; // 最大容纳人数
int minperson=2;   // 最少开始人数
//int allow_leave=1; // 不知道干嘛 取消
int allow_start=0;  // 人数够可以开始throw
int Max1=32;//一秀的个数
int Max2=16;//二举的个数
int Max3=8; //四进的个数
int Max4=4; //三红的个数
int Max5=2; //对堂的个数
int Max6=1; //状元的个数
int Realmode=0; //是否巫师主持
object* member,leader,dutang1,dutang2,winner;
//string roomname;

int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
void do_yao(string arg);
string getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
int pass_token(int,int);
int startreal();
int stopreal();
int givegift();
int qianbing(object,int);
int quitgame(object me);
int fyao(string arg);
string display_item(int,int,int,int,int,int);
int is_chat_room() {return 1;}

void init()
{
	add_action("fsit","sit");
	add_action("fleave","leave");
	add_action("fleader","leader");
	add_action("fview","view");
	add_action("fyao","throw");
	add_action("startreal","start");
	add_action("stopreal","stop");
	add_action("quitgame","quit");
	add_action("quitgame","exit");
}

int fleader(string id)
{
	int i;
	object ob = this_player();

	if (wizardp(ob))
	{
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				if (member[i]->query("id")==id)
				{
					leader=member[i];
					tell_room(environment(leader), "现在轮到"+ leader->query("name")+"掷了。\n");
					return 1;
				}
			}
			notify_fail("这个人不在这里搏饼。\n");
		}
		else notify_fail("没人在这搏饼。\n");
	}
	return 0;
}

int startreal()
{
	int i;
	object* pl;
	object ob = this_player();
	object null;
	string roomname;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");
	if (wizardp(ob))
	{
		Realmode=1;
		winner=null;
		pl=users();
		message("vision", HIY + ob->query("name") + "宣布：" + roomname + "正式开放，奖品立即兑现！\n"NOR, pl);
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				member[i]->set_temp("bobing/g1",0);       //博得bing1数量
				member[i]->set_temp("bobing/g2",0);       //博得bing2数量
				member[i]->set_temp("bobing/g3",0);       //博得bing3数量
				member[i]->set_temp("bobing/g4",0);       //博得bing4数量
				member[i]->set_temp("bobing/g5",0);       //博得bing5数量
				member[i]->set_temp("bobing/g6",0);       //博得bing6数量
				member[i]->set_temp("bobing/dest","");    //最大博到的称号
				member[i]->set_temp("bobing/maxaward",0); //最大博到的bing*数字
				member[i]->set_temp("bobing/maxscore",0); //最大博到的分数
			}
		}
		Max1=32; //一秀的个数
		Max2=16; //二举的个数
		Max3=8;  //四进的个数
		Max4=4;  //三红的个数
		Max5=2;  //对堂的个数
		Max6=1;  //状元的个数
		return 1;
	}
	return 0;
}

int stopreal()
{
	int i;
	object* pl;
	object ob = this_player();
	string roomname;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");

	if (wizardp(ob))
	{
		pl=users();
		if (Realmode==1)
		{
			message("vision", HIY + ob->query("name") + "宣布：" + roomname + "兑奖已结束，下次努力了！\n"NOR, pl);
			givegift();  //分饼
			Realmode=0;
			if (arrayp(member))
			{
				for (i=0;i<sizeof(member);i++)
				{
					member[i]->set_temp("bobing/g1",0);
					member[i]->set_temp("bobing/g2",0);
					member[i]->set_temp("bobing/g3",0);
					member[i]->set_temp("bobing/g4",0);
					member[i]->set_temp("bobing/g5",0);
					member[i]->set_temp("bobing/g6",0);
					member[i]->set_temp("bobing/dest","");
					member[i]->set_temp("bobing/maxaward",0);
					member[i]->set_temp("bobing/maxscore",0);
				}
			}
		}
		return 1;
	}
	return 0;
}

int givegift()
{
	object ob;
	int i, j, num;

	if (!arrayp(member)||sizeof(member)==0)
		notify_fail("没人在这搏饼，就别分啦。\n");
	else
	{
		for (i=0;i<sizeof(member);i++)
		{
			num=member[i]->query_temp("bobing/g1");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing1");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g2");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing2");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g3");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing3");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g4");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing4");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g5");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing5");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g6");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing6");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
//			member[i]->set("marks/bobing",1);
		}
		return 1;
	}
}

int pass_token(int index,int passmode)
{
	int i,passok;
	passok=0;
	if (passmode==0)
	{
		for (i=0;i<sizeof(member)-1;i++)
		{
			if (index>=sizeof(member)) index=index-sizeof(member);
			if (member[index]->query_temp("bobing_skip"))
			{
				member[index]->delete_temp("bobing_skip");
			}
			else if (interactive(member[index]) && environment(member[index])==this_object())
			{
				  passok=1;
				  leader=member[index];
				  break;
			}
			else
				delete_member(member[index]);
		}
//		if ((!passok)||(sizeof(member)<minperson))
		if ( sizeof(member)<minperson )
		{
			allow_start=0;
			tell_room(environment(leader), "陪你玩的人还不够，等人来了吧。\n");
		}
		else if (!passok)
			fyao(" "); //除了这个人其它都在跳过中
		else tell_room(environment(leader), "现在轮到" + leader->query("name") + "掷了。\n");
		remove_call_out("check_throw");
		if (sizeof(member)>=2)
		call_out("check_throw",30,leader);
	}
}
void check_throw(object who)
{
	if (!objectp(who)) message_vision(HIC"有人临时离开了，从下一个开始吧。\n"NOR);
	else if (!interactive(who) || environment(who)!=this_object())
		message_vision(HIC"$N暂时离开了，收回他的奖品。从下一个开始继续博。\n"NOR,who);
	else if (Max1 == 0 && Max2 == 0 && Max3 == 0 && Max4 == 0 && Max5 == 0 && Max6 == 0)
		return;
	else
	{
		message_vision(HIC"由于$N迟迟不肯掷骰子，大家一致要求收回奖品，让$N离开场地。\n"NOR,who);
	  delete_member(who);
	}
	pass_token(query_member(who),0);
}
int fyao(string arg)
{
	int i,j,k;
	object ob = this_player();

	i=query_member(ob);
	if (allow_start )
	{
		if (i>0)
		{
			if(ob==leader)
			{
				do_yao(arg);
				pass_token(i,0);
				return 1;
			}
			else notify_fail(HIC"还没轮到你呢，瞎嚷嚷个啥劲呢！\n"NOR);
		}
		else notify_fail(HIC"你要先坐下来才能和大家一起搏饼。\n"NOR);
	}
	else notify_fail(HIY"现在人还不够，悠着点吧。\n"NOR);
}

int fview()
{
	int i;
	object ob = this_player();

	if (!arrayp(member) || sizeof(member)==0)
		notify_fail("没人在这搏饼。\n");
	else
	{
		printf(HIY"  玩家          最高奖         "HIC"一秀  "HIB"二举  "HIG"四进  "HIR"三红  "HIY"对堂  "HIM"状元\n"NOR);
	        printf("┌────────────────────────────────┐\n");
		for (i=0;i<sizeof(member);i++)
		{
			printf("│%-14s%-12s%6d%6d%6d%6d%6d%6d  │\n",
				member[i]->query("name"),
				member[i]->query_temp("bobing/dest"),
				member[i]->query_temp("bobing/g1"),
				member[i]->query_temp("bobing/g2"),
				member[i]->query_temp("bobing/g3"),
				member[i]->query_temp("bobing/g4"),
				member[i]->query_temp("bobing/g5"),
				member[i]->query_temp("bobing/g6"),);
		}
		printf("└────────────────────────────────┘\n");
		printf("目前还有一秀饼%i块、二举饼%i块、四进饼%i块、三红饼%i块、对堂饼%i块。\n", Max1, Max2, Max3, Max4, Max5);
		if (objectp(winner))
			printf("现在的状元由%s保持。\n",winner->query("name"));
		if (objectp(leader))
			printf("现在该轮到%s掷了。\n",leader->query("name"));
		return 1;
	}
}

int fleave(string id)
{
	int i, num;
	object nil, ob = this_player();

	if (wizardp(ob))
	{
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				if (member[i]->query("id")==id) ob=member[i];
			}
			if (i==sizeof(member))
				notify_fail("这个人不在这里搏饼。\n");
		}
		else notify_fail("没人在这搏饼。\n");
	}
	num=query_member(ob);
	if (num)
	{
		if (leader==ob)
		{
			if (num==sizeof(member)) num=1;
			else num++;
			leader=member[num-1];
		}
	}
	else return 1;
	if (sizeof(member)>minperson)
		message_vision(HIG"$N离开了大家少了一个伙伴了！\n"NOR,ob);
	else message_vision(HIG"$N离开了大家玩不成了！\n"NOR,ob);
	Maxperson++;
	delete_member(ob);
	return 1;
}

int fsit()
{
	object ob = this_player();

	if ((int)ob->query("combat_exp") < 100)
	{
		tell_object(ob,HIY"抱歉，你就这点经验，该不会是dummy吧？\n"NOR);
		return 1;
	}

	if (!(query_member(ob)))
	{
		if (Maxperson>0)
		{
			message_vision(HIC"$N坐下来和大家一起搏饼。\n"NOR,ob);
			Maxperson--;
			add_member(ob);
			ob->set_temp("bobing/dest","");
			ob->set_temp("bobing/g1",0);
			ob->set_temp("bobing/g2",0);
			ob->set_temp("bobing/g3",0);
			ob->set_temp("bobing/g4",0);
			ob->set_temp("bobing/g5",0);
			ob->set_temp("bobing/g6",0);
			ob->set_temp("bobing/maxscore",0);
			ob->set_temp("bobing/maxaward",0);
		}
		else tell_object(ob,HIY"这一桌满了，你去别处看看吧。\n"NOR);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if (query_member(me))
		return notify_fail(HIB"你要先离开搏饼桌才能离开这里。\n"NOR);
	return 1;
}

int quitgame(object me)
{
	if (query_member(me))
		return notify_fail(HIB"你要先离开搏饼桌才能退出游戏。\n"NOR);
	return 1;
}

int delete_member(object ob)
{
	int i;
  object nil;
	int num;
	if (objectp(winner) && ob==winner)
	{
		winner->set_temp("bobing/g6",0);
		winner=nil;
	}
	num=query_member(ob);
	if (num)
	{
		if (leader==ob)
		{
			if (num==sizeof(member)) num=1;
			else num++;
			leader=member[num-1];
		}
	}
	else return 1;
	if (!arrayp(member)) return 0;
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			member-=({ob});
			Max1+=ob->query_temp("bobing/g1");
			Max2+=ob->query_temp("bobing/g2");
			Max3+=ob->query_temp("bobing/g3");
			Max4+=ob->query_temp("bobing/g4");
			Max5+=ob->query_temp("bobing/g5");
			Max6+=ob->query_temp("bobing/g6");
			ob->delete_temp("bobing");
			break;
		}
	}
	member -= ({0});
}

int add_member(object ob)
{
	if (!arrayp(member))
	{
		member=({ob});
		leader=ob;
	}
	else
	{
  	member -= ({0});
		member+=({ob});
		if (sizeof(member)>=minperson)
		{
			allow_start=1;
			if (!leader) leader = ob;
			tell_room(environment(leader), "太好了，人凑够了，可以开始玩了。\n");
			tell_room(environment(leader), leader->query("name")+"先掷吧。\n");
			remove_call_out("check_throw");
			call_out("check_throw",30,leader);
		}
	}
	return 1;
}

int query_member(object ob)
{
	int i;

	if (!arrayp(member)) return 0;
	member -= ({0});
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			return i+1;
		}
	}
	return 0;
}

void do_yao(string arg)
{
	string *sha_msg = ({
"抓起六个骰子放在手心里拼命摇，然后团起手来向手中吹了口气，口中还神神叨叨地念念有词：天灵灵，地灵灵……来来来，开了……\n",
"瞪着一对红眼，大喝一声：状元！手中的六粒骰子往碗中一摔！\n",
"往手上吹了口气，六粒骰子轻轻一抛．．．\n",
"故作镇静地将六粒骰子往碗里一抛，不料一粒骰子从指缝中一不小心掉出碗外。完了！完了！白掷了一把！\n",
"微微一笑，六粒骰子往碗里一滚．．．\n",
"望空作了个揖：菩萨保佑！六粒骰子战战兢兢地碗中一投．．．\n",
"拿着六粒骰子，抖足精神：娶老婆生孩子在此一举！\n",
"衣袖一卷，大声叫道：看我的！\n",
"咬牙切齿，六粒骰子往碗中上狠狠地一砸．．．\n",
"满头大汗，自言自语道：我不要别的，有个对堂就够了．．\n",
"潇洒地作了个四方揖：这把该我抢状元了，看好了．．．\n",
});

	int t1,s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore,msgno;
	string result,dest;
	object ob = this_player();

	getscore=0;
	dest="";

//巫师作弊
	if (wizardp(ob) && arg &&
		sscanf(arg, "%d %d %d %d %d %d", s1,s2,s3,s4,s5,s6) == 6 &&
		s1 > 0 && s1 < 7 &&
		s2 > 0 && s2 < 7 &&
		s3 > 0 && s3 < 7 &&
		s4 > 0 && s4 < 7 &&
		s5 > 0 && s5 < 7 &&
		s6 > 0 && s6 < 7)
	{
		CHANNEL_D->do_channel(ob, "sys", "不好意思，就作弊一把吧。\n");
	}
	else
	{
/*		t1=random(50)+1;
// 加大对堂概率
		if (t1==25)
		{
			s1=5; s2=2; s3=6; s4=4; s5=3; s6=1;
		}
		else
		{
*/
// 正常概率
			s1=random(6)+1;
			s2=random(6)+1;
			s3=random(6)+1;
			s4=random(6)+1;
			s5=random(6)+1;
			s6=random(6)+1;
//		}
	}
//按点数统计
	c1=countit(s1,s2,s3,s4,s5,s6,1); //一的个数
	c2=countit(s1,s2,s3,s4,s5,s6,2); //二的个数
	c3=countit(s1,s2,s3,s4,s5,s6,3); //三的个数
	c4=countit(s1,s2,s3,s4,s5,s6,4); //四的个数
	c5=countit(s1,s2,s3,s4,s5,s6,5); //五的个数
	c6=countit(s1,s2,s3,s4,s5,s6,6); //六的个数

	if (c1==6||c2==6||c3==6||c4==6||c5==6||c6==6)
	{
		getaward=6;
		if (c1==6)
		{
//			dest="六  黑(一)";
//			getscore=1201;
			dest="六  幺(一)";
			getscore=1301;
		}
		else if (c2==6)
		{
			dest="六  黑(二)";
			getscore=1202;
		}
		else if (c3==6)
		{
			dest="六  黑(三)";
			getscore=1203;
		}
		else if (c5==6)
		{
			dest="六  黑(五)";
			getscore=1205;//1204
		}
		else if (c6==6)
		{
			dest="六  黑(六)";
			getscore=1206;//1205
		}
		else if (c4==6)
		{
			dest="六  红(通吃)";
			getscore=1304;//1207
		}
	}
	else if (c4==5)
	{
		getaward=6;
		if (c1==1)
		{
			dest="五红带一";
			getscore=1101;//1102
		}
		else if (c2==1)
		{
			dest="五红带二";
			getscore=1102;//1103;
		}
		else if (c3==1)
		{
			dest="五红带三";
			getscore=1103;//1104;
		}
		else if (c5==1)
		{
			dest="五红带五";
			getscore=1105;
		}
		else if (c6==1)
		{
			dest="五红带六";
			getscore=1106;
		}
	}
	else if (c6==5)
	{
		getaward=6;
		if (c1==1)
		{
			dest="五主(六)带一";
			getscore=1001;//1046;
		}
		else if (c2==1)
		{
			dest="五主(六)带二";
			getscore=1002;//1056;
		}
		else if (c3==1)
		{
			dest="五主(六)带三";
			getscore=1003;//1066;
		}
		else if (c4==1)
		{
			dest="五主(六)带四";
			getscore=1004;//1076;
		}
		else if (c5==1)
		{
			dest="五主(六)带五";
			getscore=1005;//1086;
		}
	}
	else if (c5==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(五)带一";
			getscore=1001;//1045;
		}
		else if(c2==1)
		{
			dest="五主(五)带二";
			getscore=1002;//1055;
		}
		else if(c3==1)
		{
			dest="五主(五)带三";
			getscore=1003;//1065;
		}
		else if(c4==1)
		{
			dest="五主(五)带四";
			getscore=1004;//1075;
		}
		else if(c6==1)
		{
			dest="五主(五)带六";
			getscore=1006;//1096;
		}
	}
	else if(c3==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(三)带一";
			getscore=1001;//1043;
		}
		else if(c2==1)
		{
			dest="五主(三)带二";
			getscore=1002;//1053;
		}
		else if(c4==1)
		{
			dest="五主(三)带四";
			getscore=1004;//1073;
		}
		else if(c5==1)
		{
			dest="五主(三 )带五";
			getscore=1005;//1083;
		}
		else if(c6==1)
		{
			dest="五主(三)带六";
			getscore=1006;//1093;
		}
	}
	else if(c2==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(二)带一";
			getscore=1001;//1042;
		}
		else if(c3==1)
		{
			dest="五主(二)带三";
			getscore=1003;//1062;
		}
		else if(c4==1)
		{
			dest="五主(二)带四";
			getscore=1004;//1072;
		}
		else if(c5==1)
		{
			dest="五主(二)带五";
			getscore=1005;//1082;
		}
		else if(c6==1)
		{
			dest="五主(二)带六";
			getscore=1006;//1092;
		}
	}
	else if(c1==5)
	{
		getaward=6;
		if(c2==1)
		{
			dest="五主(一)带二";
			getscore=1002;//1051;
		}
		else if(c3==1)
		{
			dest="五主(一)带三";
			getscore=1003;//1061;
		}
		else if(c4==1)
		{
			dest="五主(一)带四";
			getscore=1004;//1071;
		}
		else if(c5==1)
		{
			dest="五主(一)带五";
			getscore=1005;//1081;
		}
		else if(c6==1)
		{
			dest="五主(一)带六";
			getscore=1006;//1091;
		}
	}
	else if (c4==4)
	{
		getaward=6;
		if((s1+s2+s3+s4+s5+s6-16)==2)
		{
			dest="状元插金花";
	//		getscore=1206;
	// 六红是 1304 六黑是 120 - 1205 应该比这些都大
	    getscore = 1402;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==12)
		{
			dest="状元带十二";
			getscore=512;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==11)
		{
			dest="状元带十一";
			getscore=511;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==10)
		{
			dest="状元带十";
			getscore=510;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==9)
		{
			dest="状元带九";
			getscore=509;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==8)
		{
			dest="状元带八";
			getscore=508;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==7)
		{
			dest="状元带七";
			getscore=507;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==6)
		{
			dest="状元带六";
			getscore=506;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==5)
		{
			dest="状元带五";
			getscore=505;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==4)
		{
			dest="状元带四";
			getscore=504;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==3)
		{
			dest="状元带三";
			getscore=503;
		}
	}
	else if (c1==4||c2==4||c3==4||c5==4||c6==4)
	{
		getaward=3;
		if (c4==2)
		{
			getscore=302;
			dest="四进带二举";
		}
		else if(c4==1)
		{
			getscore=301;
			dest="四进带一秀";
		}
		else if(c4==0)
		{
			getscore=300;
			dest="四进";
		}
	}
	else if(c4==3)
	{
		getaward=4;
		getscore=400;
		dest="三红";
	}
	else if(c4==2)
	{
		getaward=2;
		getscore=200;
		if (c1==2)
		{
			dest="二举插金花";
		}
		dest="二举";
	}
	else if (c4==1)
	{
		if (c1==1&&c2==1&&c3==1&&c5==1&&c6==1)
		{
			getaward=5;
			getscore=500;
			dest="对堂";
		}
		else if (c1==2)
		{
			getaward=1;
			getscore=100;
			dest="一秀插金花";
		}
		else
		{
			getaward=1;
			getscore=100;
			dest="一秀";
		}
	}
	else
	{
		getaward=0;
		getscore=0;
		dest=NOR"………哇塞！居然什么都不是耶！？呵呵呵呵，真同情你哦";
	}
	result=display_item(s1,s2,s3,s4,s5,s6);
	msgno = random(sizeof(sha_msg));
	if (msgno != 3) result=result+"\n居然是个"HIR+dest+NOR"？加油啊！\n";
	else 
	 {
	 	result=result+"\n跳槽了，让别人掷！\n";
	 	ob->set_temp("bobing_skip",1);//下一轮轮空
	 }
	message_vision(HIC"$N"+sha_msg[msgno]+NOR+result,ob);
	if (msgno != 3) getit(ob,getaward,getscore,dest);
}

string checkcolor(int i)
{
	if (i==1||i==4) return RED;
	else return GRN;
}

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
{
	int i;

	i=0;
	if (s1==sd) i++;
	if (s2==sd) i++;
	if (s3==sd) i++;
	if (s4==sd) i++;
	if (s5==sd) i++;
	if (s6==sd) i++;
	return i;
}

string getit(object ob,int getaward,int getscore,string dest)
{
	object* play;
	string roomname;
	int i;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");
/*	if (getaward > (ob->query_temp("bobing/maxaward")))
	{
		ob->set_temp("bobing/maxaward",getaward );
		ob->set_temp("bobing/dest",dest);
	}
	if (getscore>(ob->query_temp("bobing/maxscore")))
		ob->set_temp("bobing/maxscore",getscore);*/
	if (getscore > (ob->query_temp("bobing/maxscore")))
	{
		ob->set_temp("bobing/maxaward",getaward );
		ob->set_temp("bobing/dest",dest);
  	ob->set_temp("bobing/maxscore",getscore);
	}	
	if (getaward==1)
	{
		if (Max1<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N搏到一秀一个，真是可惜，没有奖品……\n"NOR, ob);
		}
		else
		{
			ob->add_temp("bobing/g1",1);
//			Max1=(Max1==0)?0:Max1-1;
       Max1 --;
			if (Realmode)
				message_vision(HIY"$N搏到一秀一个，奖一秀饼一块！\n"NOR, ob);
			else
				message_vision(CYN"$N搏到一秀一个，真是可惜巫师不在，没有奖品……\n"NOR, ob);
		}
	}
	if (getaward==2)
	{
		if (Max2<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N搏到二举一个，真是可惜，没有奖品……\n"NOR,ob);
		}
		else
		{
//			ob->set_temp("bobing/g2",ob->query_temp("bobing/g2")+1);
//			Max2=(Max2==0)?0:Max2-1;
      ob->add_temp("bobing/g2",1);
      Max2 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到二举一个，奖二举饼一块！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到二举一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==3)
	{
		if (Max3<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N搏到四进一个，真是可惜，没有奖品……\n"NOR,ob);
		}
		else
		{
//			ob->set_temp("bobing/g3",ob->query_temp("bobing/g3")+1);
//			Max3=(Max3==0)?0:Max3-1;
      ob->add_temp("bobing/g3",1);
      Max3 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到四进一个，奖四进饼一块！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到四进一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
    //
    if (getscore == 302) //四进带二举
    getit(ob,2,0,0);	
    if (getscore == 301) //四进带一秀
    getit(ob,1,0,0);
	}
	if (getaward==4)
	{
		if (Max4<=0 )
		{
			qianbing(ob,getaward);
		}
		else
		{
//			ob->set_temp("bobing/g4",ob->query_temp("bobing/g4")+1);
//			Max4=(Max4==0)?0:Max4-1;
      ob->add_temp("bobing/g4",1);
      Max4 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到三红一个，奖三红饼一块！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到三红一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==5)
	{
		if (Max5<=0 )
		{
			qianbing(ob,getaward);
		}
		else
		{
//			ob->set_temp("bobing/g5",ob->query_temp("bobing/g5")+1);
//			Max5=(Max5==0)?0:Max5-1;
      ob->add_temp("bobing/g5",1);
      Max5 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到对堂一个，奖对堂饼一块！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到对堂一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if(getaward>=6)
	{
		if(Realmode) 
//		  Max6=(Max6==0)?0:Max6-1;
		  Max6=0;
		else
			message_vision(CYN"$N搏到状元一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		if(!objectp(winner))
		{
			winner=ob;
			ob->set_temp("bobing/g6",1);
			play=users();
			message("vision", HIY"\n\n[搏饼最新消息]\n───────────────────────\n恭喜！ 恭喜！" + ob->query("name") + "搏到了" + dest + "！成为 " + roomname+"的状元！！！\n"NOR, play);
		}
		else
		{
			if (ob!=winner &&
				getscore>winner->query_temp("bobing/maxscore"))
			{
				winner->set_temp("bobing/g6",0);
				winner=ob;
				winner->set_temp("bobing/g6",1);
				play=users();
				message("vision", HIY"\n\n[搏饼最新消息]\n───────────────────────\n恭喜！ 恭喜！" + ob->query("name") + "搏到了" + dest + "！成为 " + roomname+"的状元！！！\n"NOR, play);
			}
			else
				message_vision(CYN"$N搏到状元一个，真是可惜你的状元没有奖品……\n"NOR,ob);
		}
		if (getscore == 1004)//五主带四 奖励一个一秀
		getit(ob,1,0,0);
		if (getscore == 1304) //六红通吃
		{
			if (arrayp(member))
			{
				for (i=0;i<sizeof(member);i++)
				{
					member[i]->set_temp("bobing/g1",0);
					member[i]->set_temp("bobing/g2",0);
					member[i]->set_temp("bobing/g3",0);
					member[i]->set_temp("bobing/g4",0);
					member[i]->set_temp("bobing/g5",0);
					member[i]->set_temp("bobing/g6",0);
				}
			}
			ob->set_temp("bobing/g1",32);
			ob->set_temp("bobing/g2",16);
			ob->set_temp("bobing/g3",8);
			ob->set_temp("bobing/g4",4);
			ob->set_temp("bobing/g5",2);
			ob->set_temp("bobing/g6",1);
	Max1=0;//一秀的个数
	Max2=0;//二举的个数
	Max3=0; //四进的个数
	Max4=0; //三红的个数
	Max5=0; //对堂的个数
	Max6=0; //状元的个数			
		}
		if (getscore == 1402)//状元插金花 拿两个对堂
		{
			getit(ob,5,0,0);
			getit(ob,5,0,0);
		}
	}
}

int qianbing(object ob,int getaward)
{
	int i, flag;

	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]->query("name")==ob->query("name"))
		{
			flag=i;
			for (i=flag-1;i!=flag;i--)
			{
				if (i<0) i=sizeof(member)-1;
				switch (getaward)
				{
					case 1:
						if (member[i]->query_temp("bobing/g1"))
						{
							member[i]->add_temp("bobing/g1",-1);
							ob->add_temp("bobing/g1",1);
							message_vision(HIY "$N搏到一秀一个，抢了$n一秀饼一块！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 2:
						if (member[i]->query_temp("bobing/g2"))
						{
							member[i]->add_temp("bobing/g2",-1);
							ob->add_temp("bobing/g2",1);
							message_vision(HIY "$N搏到二举一个，抢了$n二举饼一块！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 3:
						if (member[i]->query_temp("bobing/g3"))
						{
							member[i]->add_temp("bobing/g3",-1);
							ob->add_temp("bobing/g3",1);
							message_vision(HIY "$N搏到四进一个，抢了$n四进饼一块！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 4:
						if (member[i]->query_temp("bobing/g4"))
						{
							member[i]->add_temp("bobing/g4",-1);
							ob->add_temp("bobing/g4",1);
							message_vision(HIY "$N搏到三红一个，抢了$n三红饼一块！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 5:
						if (member[i]->query_temp("bobing/g5"))
						{
							member[i]->add_temp("bobing/g5",-1);
							ob->add_temp("bobing/g5",1);
							message_vision(HIY "$N搏到对堂一个，抢了$n对堂饼一块！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					default:
						message_vision(HIY "$N搏到一块没有用的饼！\n"NOR,ob);
						break;
				}
			}
			message_vision(HIY"$N抢不到一块有用的饼！\n"NOR,ob);
			return 0;
		}
	}
	message_vision(HIY"$N居然找不到自己座位！\n"NOR,ob);
	return 0;
}

string display_item(int i1, int i2, int i3, int i4, int i5, int i6)
{
	string str;
	str = "┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐\n";
	switch (i1)
	{
		case 1:
		case 2:
			str = str+"│　　　│";
			break;
		case 3:
			str = str+"│"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+"│"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+"│"GRN"●　●"NOR"│";
			break;
	}
	switch (i2)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i3)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i4)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i5)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i6)
	{
		case 1:
		case 2:
			str = str+" │　　　│\n";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│\n";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│\n";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│\n";
			break;
	}
/* 第一行. 真累! */
	switch (i1)
	{
		case 1:
			str = str+"│"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+"│"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+"│"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+"│　　　│";
			break;
	}
	switch (i2)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i3)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i4)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i5)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i6)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│\n";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│\n";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│\n";
			break;
		case 4:
			str = str+" │　　　│\n";
			break;
	}
/* 第二行. 累死我了! */
	switch (i1)
	{
		case 1:
		case 2:
			str = str+"│　　　│";
			break;
		case 3:
			str = str+"│"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+"│"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+"│"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i2)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i3)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i4)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i5)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i6)
	{
		case 1:
		case 2:
			str = str+" │　　　│\n";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│\n";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│\n";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│\n"NOR;
			break;
	}
/* 第三行. 总算搞完了! */
	str = str+"└───┘ └───┘ └───┘ └───┘ └───┘ └───┘\n";
	return str;
}
/*
中秋博饼及其规则

　

每逢中秋佳节，厦门和台湾地区，以及海内外闽台人士的居住地，都盛行一种“玩会饼博状元”的习俗。该习俗源于明末清初。当时郑成功的部将洪旭，为了缓解士兵们的思乡之情，激励士兵，与手下一起推敲，巧制中秋会饼，让全体将士在中秋夜欢聚博饼。今天，厦门鼓浪屿上还有当年博饼的雕塑。

一套中秋会饼中，共有大小不同的63块饼。依大小顺序分别为：状元饼1块；榜眼（对堂）饼2块；探花（三红）饼4块；进士（四进）饼8块；举人（二举）饼16块，秀才（一秀）饼32块；象征古代四级考试。之所以有63块饼，是因为，在古代，数字的使用是有等级之分的。81是帝王所用之数，72是千岁和亲王所用之数，郑成功封过延平王，所以用63。

博饼的玩法是：一群人围在一个大瓷碗边，轮流向瓷碗内投掷骰子，一次同时投掷6颗骰子，根据骰子的排列组合，来决定投掷者应分得什么样的饼。一直玩到所有的饼分配完毕为止。

博饼一共有57个博规，见下表：

名称
 排列组合
 得饼说明
 
状元插金花
 四粒红四点，二粒红一点
 可得状元和两个对堂，不被追缴
 
红 六 勃
 六粒红四点
 可追缴全部的饼，但得主要请大家吃饼，只是请多少，要由得主决定
 
幺点六勃
 六粒红一点
 得状元，可被追缴，要请客
 
黑 六 勃
 六粒六点（二点、三点、五点）
 会饼由大家平分
 
五 王
 五粒红四点
 得状元，可被追缴
 
五 子
 五粒一点（二点、三点、五点、六点）
 得状元，可被追缴
 
状 元
 四粒红四点
 得状元，可被追缴
 
对 堂
 同时出现一、二、三、四、五、六点
 得对堂一个，可被追缴
 
三 红
 三粒红四点
 得三红一个，可被追缴
 
四 进
 四粒一点（二点、三点、五点、六点）
 得四进一个，不被追缴
 
二 举
 两粒红四点
 得二举一个，不被追缴
 
一 秀
 一粒红四点
 得一秀一个，不被追缴
 
　

　

附注
 如果没有出现上述排列组合中的任何一种情形，则投掷者什么也得不到；如果投掷过程中有骰子溢出瓷碗，则投掷者不仅什么也得不到，下一轮还要轮空；

当五子得主的另1粒骰子是红四点时，他还可以得一秀一个；

当四进得主的另2粒骰子均为红四点时，他还可以得二举一个；

当四进得主的另2粒骰子中只有一粒红四点时，他还可以得一秀一个；

如果一个排列组合可以符合多种情形时，按最大者，即按排在表中最上层者，算。如两粒红四点，得二举一个，而不能得一秀两个；

在会饼全部分配完毕前，自第五个三红得主起，后来的三红得主均可以按顺序追缴前面三红得主的三红饼一个；同样，自第三个对堂得主起，后来的对堂得主，也可以按顺序追缴前面对堂得主的对堂饼一个；

状元饼的分配，则按大小来算，排在表中上层的为大，如果同时出现五王或五子，则按剩下的那个骰子的点数大小来算，点数大者胜；如果同时出现多人有四粒红四点，则按剩下的2粒骰子的点数之和的大小来算，大者胜；如果点数相同，则先掷出者胜。
 

随着社会经济的发展，会饼中的月饼早就被其它物品所取代，比如：网球拍、牙膏、香皂、摩托车、金项链什么的，只是博规还基本没有改变。

　
*/