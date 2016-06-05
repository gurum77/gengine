#pragma once

/**
	@brief
		- text object
*/
class G_EXT_CLASS CGObjectText :
	public CGCompoundObjectBase
{
public:
	const CGText &GetText() const;
	CGText &GetText();
	void SetText(const CGText &text);

	void SetFontProperty(const CGFontProperty &fontProperty);
	const CGFontProperty &GetFontProperty() const;
	CGFontProperty &GetFontProperty();

private:
	CGText m_text;
	CGFontProperty m_fontProperty;

protected:
	virtual void GenerateSubObject();

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("TEXT"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyLine; };

	GDEFINE_REGISTE_OBJECT(CGObjectText)
	CGObjectText(void);
	virtual ~CGObjectText(void);
};

