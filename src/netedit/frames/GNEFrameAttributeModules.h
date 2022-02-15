/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2022 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GNEFrameAttributeModules.h
/// @author  Pablo Alvarez Lopez
/// @date    Aug 2019
///
// Auxiliar class for GNEFrame Modules (only for attributes edition)
/****************************************************************************/
#pragma once
#include <config.h>

#include <netedit/elements/GNEAttributeCarrier.h>
#include <netedit/GNEViewNetHelper.h>
#include <utils/common/Parameterised.h>
#include <utils/foxtools/FXGroupBoxModule.h>
#include <utils/xml/CommonXMLStructure.h>

// ===========================================================================
// class declaration
// ===========================================================================

class GNEFrame;

// ===========================================================================
// class definitions
// ===========================================================================

class GNEFrameAttributeModules {

public:
    // ===========================================================================
    // class declaration
    // ===========================================================================

    class AttributesCreator;
    class AttributesEditor;
    class AttributesCreatorFlow;
    class AttributesEditorFlow;

    // ===========================================================================
    // class AttributesCreatorRow
    // ===========================================================================

    class AttributesCreatorRow : public FXHorizontalFrame {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesCreatorRow)

    public:
        /// @brief constructor
        AttributesCreatorRow(AttributesCreator* AttributesCreatorParent, const GNEAttributeProperties& attrProperties);

        /// @brief destroy AttributesCreatorRow (but don't delete)
        void destroy();

        /// @brief return Attr
        const GNEAttributeProperties& getAttrProperties() const;

        /// @brief return value
        std::string getValue() const;

        /// @brief return status of label checkbox button
        bool getAttributeCheckButtonCheck() const;

        /// @brief enable or disable label checkbox button for optional attributes
        void setAttributeCheckButtonCheck(bool value);

        /// @brief enable row
        void enableAttributesCreatorRow();

        /// @brief disable row
        void disableAttributesCreatorRow();

        /// @brief check if row is enabled
        bool isAttributesCreatorRowEnabled() const;

        /// @brief refresh row
        void refreshRow();

        /// @brief disable Rows
        void disableRow();

        /// @brief check if current attribute is valid
        bool isAttributeValid() const;

        /// @brief get AttributesCreator parent
        AttributesCreator* getAttributesCreatorParent() const;

        /// @name FOX-callbacks
        /// @{
        /// @brief called when user set the value of an attribute of type int/float/string/bool
        long onCmdSetAttribute(FXObject*, FXSelector, void*);

        /// @brief called when user press the open dialog button
        long onCmdOpenAttributeDialog(FXObject*, FXSelector, void*);
        /// @}

    protected:
        FOX_CONSTRUCTOR(AttributesCreatorRow)

        /// @brief generate ID
        std::string generateID() const;

        /// @brief check if current ID placed in myValueTextField is valid
        bool isValidID() const;

    private:
        /// @brief pointer to AttributesCreator
        AttributesCreator* myAttributesCreatorParent = nullptr;

        /// @brief attribute properties
        const GNEAttributeProperties myAttrProperties;

        /// @brief string which indicates the reason due current value is invalid
        std::string myInvalidValue;

        /// @brief Label with the name of the attribute
        FXLabel* myAttributeLabel = nullptr;

        /// @brief check button to enable/disable Label attribute
        FXCheckButton* myEnableAttributeCheckButton = nullptr;

        /// @brief Button for open color or allow/disallow editor
        FXButton* myAttributeButton = nullptr;

        /// @brief textField to modify the default value of string parameters
        FXTextField* myValueTextField = nullptr;

        /// @brief check button to enable/disable the value of boolean parameters
        FXCheckButton* myValueCheckButton = nullptr;

        /// @brief comboBox for discrete vaues
        FXComboBox* myValueComboBox = nullptr;
    };

    // ===========================================================================
    // class AttributesCreator
    // ===========================================================================

    class AttributesCreator : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesCreator)

        // declare friend class
        friend class Row;

    public:
        /// @brief constructor
        AttributesCreator(GNEFrame* frameParent);

        /// @brief destructor
        ~AttributesCreator();

        /// @brief show AttributesCreator modul
        void showAttributesCreatorModule(GNEAttributeCarrier* templateAC, const std::vector<SumoXMLAttr>& hiddenAttributes);

        /// @brief hide group box
        void hideAttributesCreatorModule();

        /// @brief return frame parent
        GNEFrame* getFrameParent() const;

        /// @brief get attributes and their values
        void getAttributesAndValues(CommonXMLStructure::SumoBaseObject* baseObject, bool includeAll) const;

        /// @brief get current template AC
        GNEAttributeCarrier* getCurrentTemplateAC() const;

        /// @brief check if parameters of attributes are valid
        bool areValuesValid() const;

        /// @brief show warning message with information about non-valid attributes
        void showWarningMessage(std::string extra = "") const;

        /// @brief refresh attribute creator
        void refreshAttributesCreator();

        /// @brief disable AttributesCreator
        void disableAttributesCreator();

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when reset button is pressed
        long onCmdReset(FXObject*, FXSelector, void*);

        /// @brief Called when help button is pressed
        long onCmdHelp(FXObject*, FXSelector, void*);

        /// @}

    protected:
        /// @brief FOX need this
        FOX_CONSTRUCTOR(AttributesCreator);

        /// @brief refresh rows
        void refreshRows(const bool createRows);

    private:
        /// @brief pointer to Frame Parent
        GNEFrame* myFrameParent = nullptr;

        /// @brief pointer to myAttributesCreatorFlow
        AttributesCreatorFlow* myAttributesCreatorFlow = nullptr;

        /// @brief current templateAC
        GNEAttributeCarrier* myTemplateAC;

        /// @brief hidden attributes
        std::vector<SumoXMLAttr> myHiddenAttributes;

        /// @brief vector with the AttributesCreatorRow
        std::vector<AttributesCreatorRow*> myAttributesCreatorRows;

        /// @brief frame buttons
        FXHorizontalFrame* myFrameButtons = nullptr;

        /// @brief reset button
        FXButton* myResetButton = nullptr;
    };

    // ===========================================================================
    // class AttributesCreatorFlow
    // ===========================================================================

    class AttributesCreatorFlow : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesCreatorFlow)

    public:
        /// @brief constructor
        AttributesCreatorFlow(AttributesCreator* attributesCreatorParent);

        /// @brief destructor
        ~AttributesCreatorFlow();

        /// @brief show AttributesCreatorFlow modul
        void showAttributesCreatorFlowModule();

        /// @brief hide group box
        void hideAttributesCreatorFlowModule();

        /// @brief shown AttributesCreatorFlow modul
        bool shownAttributesCreatorFlowModule() const;

        /// @brief refresh AttributesCreatorFlow
        void refreshAttributesCreatorFlow();

        /// @brief set parameters
        void setFlowParameters(CommonXMLStructure::SumoBaseObject* baseObject);

        /// @brief check if parameters of attributes are valid
        bool areValuesValid() const;

        /// @brief show warning message with information about non-valid attributes
        void showWarningMessage(std::string extra = "") const;

        /// @name FOX-callbacks
        /// @{
        /// @brief called when user set the value of an attribute of type int/float/string/bool
        long onCmdSetFlowAttribute(FXObject*, FXSelector, void*);

        /// @brief called when user press a radio button
        long onCmdSelectFlowRadioButton(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief FOX need this
        FOX_CONSTRUCTOR(AttributesCreatorFlow);

    private:
        /// @brief pointer to Attributes Creator Parent
        AttributesCreator* myAttributesCreatorParent;

        /// @brief ComboBox for option A (end, number, end/number)
        FXComboBox* myOptionAComboBox = nullptr;

        /// @brief ComboBox for definition B (perHour, period, probability)
        FXComboBox* myOptionBComboBox = nullptr;

        /// @brief horizontal frame for defition A
        FXHorizontalFrame* myOptionAHorizontalFrame = nullptr;

        /// @brief Label for option A
        FXLabel* myOptionALabel = nullptr;

        /// @brief textField for option A attribute
        FXTextField* myOptionATextField = nullptr;

        /// @brief horizontal frame for defition B
        FXHorizontalFrame* myOptionBHorizontalFrame = nullptr;

        /// @brief Label for option B
        FXLabel* myOptionBLabel = nullptr;

        /// @brief textField for option B attribute
        FXTextField* myOptionBTextField = nullptr;

        /// @brief per hours attr (vehicles/person/container)
        SumoXMLAttr myPerHourAttr = SUMO_ATTR_NOTHING;
    };

    // ===========================================================================
    // class AttributesEditorRow
    // ===========================================================================

    class AttributesEditorRow : protected FXHorizontalFrame {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesEditorRow)

    public:
        /// @brief constructor
        AttributesEditorRow(AttributesEditor* attributeEditorParent, const GNEAttributeProperties& ACAttr, const std::string& value,
                            const bool attributeEnabled, const bool computed);

        /// @brief destroy AttributesCreatorRow (but don't delete)
        void destroy();

        /// @brief refresh current row
        void refreshAttributesEditorRow(const std::string& value, const bool forceRefresh, const bool attributeEnabled, const bool computed);

        /// @brief check if current attribute of TextField/ComboBox is valid
        bool isAttributesEditorRowValid() const;

        /// @name FOX-callbacks
        /// @{

        /// @brief try to set new attribute value
        long onCmdSetAttribute(FXObject*, FXSelector, void*);

        /// @brief called when user press a check button
        long onCmdSelectCheckButton(FXObject*, FXSelector, void*);

        /// @brief open model dialog for more comfortable attribute editing
        long onCmdOpenAttributeDialog(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief default constructor
        AttributesEditorRow();

        /// @brief removed invalid spaces of Positions and shapes
        std::string stripWhitespaceAfterComma(const std::string& stringValue);

        /// @brief check junction merging
        bool mergeJunction(SumoXMLAttr attr, const std::vector<GNEAttributeCarrier*>& inspectedACs, const std::string& newVal) const;

    private:
        /// @brief pointer to AttributesEditor parent
        AttributesEditor* myAttributesEditorParent;

        /// @brief current AC Attribute
        const GNEAttributeProperties myACAttr;

        /// @brief flag to check if input element contains multiple values
        const bool myMultiple;

        /// @brief pointer to attribute label
        FXLabel* myAttributeLabel = nullptr;

        /// @brief pointer to attribute  menu check
        FXCheckButton* myAttributeCheckButton = nullptr;

        /// @brief pointer to buttonCombinableChoices
        FXButton* myAttributeButtonCombinableChoices = nullptr;

        /// @brief Button for open color editor
        FXButton* myAttributeColorButton = nullptr;

        /// @brief textField to modify the value of string attributes
        FXTextField* myValueTextField = nullptr;

        /// @brief pointer to combo box choices
        FXComboBox* myValueComboBoxChoices = nullptr;

        /// @brief pointer to menu check
        FXCheckButton* myValueCheckButton = nullptr;
    };

    // ===========================================================================
    // class AttributesEditor
    // ===========================================================================

    class AttributesEditor : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesEditor)

    public:
        /// @brief constructor
        AttributesEditor(GNEFrame* inspectorFrameParent);

        /// @brief show attributes of multiple ACs
        void showAttributeEditorModule(bool includeExtended, bool forceAttributeEnabled);

        /// @brief hide attribute editor
        void hideAttributesEditorModule();

        /// @brief refresh attribute editor (only the valid values will be refresh)
        void refreshAttributeEditor(bool forceRefreshShape, bool forceRefreshPosition);

        /// @brief pointer to GNEFrame parent
        GNEFrame* getFrameParent() const;

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when user press the help button
        long onCmdAttributesEditorHelp(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief fox need this
        FOX_CONSTRUCTOR(AttributesEditor)

    private:
        /// @brief pointer to GNEFrame parent
        GNEFrame* myFrameParent;

        /// @brief pointer to attributesEditorFlow
        AttributesEditorFlow* myAttributesEditorFlow = nullptr;

        /// @brief list of Attribute editor rows
        std::vector<AttributesEditorRow*> myAttributesEditorRows;

        /// @brief button for help
        FXButton* myHelpButton = nullptr;

        /// @brief flag used to mark if current edited ACs are bein edited including extended attribute
        bool myIncludeExtended;
    };

    // ===========================================================================
    // class AttributesEditorFlow
    // ===========================================================================

    class AttributesEditorFlow : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesEditorFlow)

    public:
        /// @brief constructor
        AttributesEditorFlow(AttributesEditor* attributesEditorParent);

        /// @brief show attributes editor Flow Module
        void showAttributeEditorFlowModule();

        /// @brief hide attribute EditorFlow
        void hideAttributesEditorFlowModule();

        /// @brief check if attribute editor flow modul is shown
        bool isAttributesEditorFlowModuleShown() const;

        /// @brief refresh attribute EditorFlow (only the valid values will be refresh)
        void refreshAttributeEditorFlow();

        /// @name FOX-callbacks
        /// @{
        /// @brief called when user set the value of an attribute of type int/float/string/bool
        long onCmdSetFlowAttribute(FXObject*, FXSelector, void*);

        /// @brief called when user press a radio button
        long onCmdSelectFlowRadioButton(FXObject*, FXSelector, void*);
        /// @}

    protected:
        FOX_CONSTRUCTOR(AttributesEditorFlow)

        /// @brief refresh end
        void refreshEnd();

        /// @brief refresh parameter number
        void refreshNumber();

        /// @brief refresh parameter VehsPerHour
        void refreshVehsPerHour();

        /// @brief refresh parameter Period
        void refreshPeriod();

        /// @brief refresh parameter Probability
        void refreshProbability();

    private:
        /// @brief pointer to AttributesEditor parent
        AttributesEditor* myAttributesEditorParent = nullptr;

        /// @brief Radio button for 'end' attribute
        FXRadioButton* myAttributeEndRadioButton = nullptr;

        /// @brief textField for 'end' attribute
        FXTextField* myValueEndTextField = nullptr;

        /// @brief Radio button for 'number' attribute
        FXRadioButton* myAttributeNumberRadioButton = nullptr;

        /// @brief textField for 'number' attribute
        FXTextField* myValueNumberTextField = nullptr;

        /// @brief Radio button for 'VehsPerHour' attribute
        FXRadioButton* myAttributeVehsPerHourRadioButton = nullptr;

        /// @brief textField for 'VehsPerHour' attribute
        FXTextField* myValueVehsPerHourTextField = nullptr;

        /// @brief Radio button for 'period' attribute
        FXRadioButton* myAttributePeriodRadioButton = nullptr;

        /// @brief textField for 'period' attribute
        FXTextField* myValuePeriodTextField = nullptr;

        /// @brief Radio button for 'probability' attribute
        FXRadioButton* myAttributeProbabilityRadioButton = nullptr;

        /// @brief textField for 'probability' attribute
        FXTextField* myValueProbabilityTextField = nullptr;
    };

    // ===========================================================================
    // class AttributesEditorExtended
    // ===========================================================================

    class AttributesEditorExtended : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::AttributesEditorExtended)

    public:
        /// @brief constructor
        AttributesEditorExtended(GNEFrame* frameParent);

        /// @brief destructor
        ~AttributesEditorExtended();

        /// @brief show AttributesEditorExtended modul
        void showAttributesEditorExtendedModule();

        /// @brief hide group box
        void hideAttributesEditorExtendedModule();

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when open dialog button is clicked
        long onCmdOpenDialog(FXObject*, FXSelector, void*);
        /// @}

    protected:
        FOX_CONSTRUCTOR(AttributesEditorExtended)

    private:
        /// @brief pointer to Frame Parent
        GNEFrame* myFrameParent = nullptr;
    };

    // ===========================================================================
    // class GenericDataAttributes
    // ===========================================================================

    class GenericDataAttributes : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::GenericDataAttributes)

    public:
        /// @brief constructor
        GenericDataAttributes(GNEFrame* frameParent);

        /// @brief destructor
        ~GenericDataAttributes();

        /// @brief show netedit attributes EditorCreator
        void showGenericDataAttributes();

        /// @brief hide netedit attributes EditorCreator
        void hideGenericDataAttributes();

        /// @brief refresh netedit attributes
        void refreshGenericDataAttributes();

        /// @brief get parameters as map
        const std::map<std::string, std::string>& getParametersMap() const;

        /// @brief get parameters as string
        std::string getParametersStr() const;

        /// @brief get parameters as vector of strings
        std::vector<std::pair<std::string, std::string> > getParameters() const;

        /// @brief set parameters
        void setParameters(const std::vector<std::pair<std::string, std::string> >& parameters);

        /// @brief pointer to frame parent
        GNEFrame* getFrameParent() const;

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when user clicks over add parameter
        long onCmdEditParameters(FXObject*, FXSelector, void*);

        /// @brief Called when user udpate the parameter text field
        long onCmdSetParameters(FXObject*, FXSelector, void*);
        /// @}

    protected:
        FOX_CONSTRUCTOR(GenericDataAttributes)

    private:
        /// @brief pointer to frame parent
        GNEFrame* myFrameParent = nullptr;

        /// @brief pointer to current map of parameters
        std::map<std::string, std::string> myParameters;

        /// @brief text field for write parameters
        FXTextField* myTextFieldParameters = nullptr;

        /// @brief button for edit parameters using specific dialog
        FXButton* myButtonEditParameters = nullptr;
    };

    // ===========================================================================
    // class DrawingShape
    // ===========================================================================

    class DrawingShape : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::DrawingShape)

    public:
        /// @brief constructor
        DrawingShape(GNEFrame* frameParent);

        /// @brief destructor
        ~DrawingShape();

        /// @brief show Drawing mode
        void showDrawingShape();

        /// @brief hide Drawing mode
        void hideDrawingShape();

        /// @brief start drawing
        void startDrawing();

        /// @brief stop drawing and check if shape can be created
        void stopDrawing();

        /// @brief abort drawing
        void abortDrawing();

        /// @brief add new point to temporal shape
        void addNewPoint(const Position& P);

        /// @brief remove last added point
        void removeLastPoint();

        /// @brief get Temporal shape
        const PositionVector& getTemporalShape() const;

        /// @brief return true if currently a shape is drawed
        bool isDrawing() const;

        /// @brief enable or disable delete last created point
        void setDeleteLastCreatedPoint(bool value);

        /// @brief get flag delete last created point
        bool getDeleteLastCreatedPoint();

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when the user press start drawing button
        long onCmdStartDrawing(FXObject*, FXSelector, void*);

        /// @brief Called when the user press stop drawing button
        long onCmdStopDrawing(FXObject*, FXSelector, void*);

        /// @brief Called when the user press abort drawing button
        long onCmdAbortDrawing(FXObject*, FXSelector, void*);
        /// @}

    protected:
        FOX_CONSTRUCTOR(DrawingShape)

    private:
        /// @brief pointer to frame parent
        GNEFrame* myFrameParent;

        /// @brief flag to enable/disable delete point mode
        bool myDeleteLastCreatedPoint;

        /// @brief current drawed shape
        PositionVector myTemporalShapeShape;

        /// @brief button for start drawing
        FXButton* myStartDrawingButton;

        /// @brief button for stop drawing
        FXButton* myStopDrawingButton;

        /// @brief button for abort drawing
        FXButton* myAbortDrawingButton;

        /// @brief Label with information
        FXLabel* myInformationLabel;
    };

    // ===========================================================================
    // class NeteditAttributes
    // ===========================================================================

    class NeteditAttributes : public FXGroupBoxModule {
        /// @brief FOX-declaration
        FXDECLARE(GNEFrameAttributeModules::NeteditAttributes)

    public:
        /// @brief constructor
        NeteditAttributes(GNEFrame* frameParent);

        /// @brief destructor
        ~NeteditAttributes();

        /// @brief show Netedit attributes modul
        void showNeteditAttributesModule(const GNETagProperties& tagValue);

        /// @brief hide Netedit attributes modul
        void hideNeteditAttributesModule();

        /// @brief fill valuesMap with netedit attributes
        bool getNeteditAttributesAndValues(CommonXMLStructure::SumoBaseObject* baseObject, const GNELane* lane) const;

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when user changes some element of NeteditAttributes
        long onCmdSetNeteditAttribute(FXObject*, FXSelector, void*);

        /// @brief Called when user press the help button
        long onCmdHelp(FXObject*, FXSelector, void*);
        /// @}

    protected:
        FOX_CONSTRUCTOR(NeteditAttributes)

    private:
        /// @brief list of the reference points
        enum class AdditionalReferencePoint {
            LEFT,
            RIGHT,
            CENTER,
            INVALID
        };

        /// @brief obtain the Start position values of StoppingPlaces and E2 detector over the lane
        double setStartPosition(double positionOfTheMouseOverLane, double lengthOfAdditional) const;

        /// @brief obtain the End position values of StoppingPlaces and E2 detector over the lane
        double setEndPosition(double positionOfTheMouseOverLane, double lengthOfAdditional) const;

        /// @brief pointer to frame parent
        GNEFrame* myFrameParent;

        /// @brief match box with the list of reference points
        FXComboBox* myReferencePointMatchBox;

        /// @brief horizontal frame for length
        FXHorizontalFrame* myLengthFrame;

        /// @brief textField for length
        FXTextField* myLengthTextField;

        /// @brief horizontal frame for close polygon
        FXHorizontalFrame* myCloseShapeFrame;

        /// @brief checkbox to enable/disable close polygon
        FXCheckButton* myCloseShapeCheckButton;

        /// @brief horizontal frame for center view after creation frame
        FXHorizontalFrame* myCenterViewAfterCreationFrame;

        /// @brief checkbox to enable/disable center element after creation
        FXCheckButton* myCenterViewAfterCreationButton;

        /// @brief Button for help about the reference point
        FXButton* helpReferencePoint;

        /// @brief Flag to check if current length is valid
        bool myCurrentLengthValid;

        /// @brief actual additional reference point selected in the match Box
        AdditionalReferencePoint myActualAdditionalReferencePoint;
    };

    /// @brief return true if AC can be edited in the current supermode
    static bool isSupermodeValid(const GNEViewNet* viewNet, const GNEAttributeCarrier* AC);

    /// @brief return true if give ACAttr can be edited in the current supermode
    static bool isSupermodeValid(const GNEViewNet* viewNet, const GNEAttributeProperties& ACAttr);
};
